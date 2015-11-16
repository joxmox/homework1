#pragma once

#include <fstream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <iostream>

namespace SEB {
    namespace db {

		// System API functions
		extern "C" {
			int truncate(const char* path, size_t length);
		}

		using namespace std;

		enum class OpenMode {
			in, out, inout
		};

		template<typename Record>
		class IndexedFile {
			constexpr static size_t       SIZE = sizeof(Record);
			string                        filename;
			fstream                       file;
			unordered_map<string, size_t> index;
			OpenMode					  omode;

			ios_base::openmode translate(const OpenMode& mode) const {
				ios_base::openmode m = ios_base::binary;
				switch (mode) {
				case OpenMode::in:
					m  |= ios_base::in;
					break;
				case OpenMode::out:
					m |=ios_base::out;
					break;
				case OpenMode::inout:
					m |=ios_base::in | ios_base::out;
					break;
				default:
					throw invalid_argument("Invalid open mode");
				}
				return m;
			}

			void buildIndex() {
				index.clear();
				size_t k = 0;
				for (auto r : (*this)) {
					index[r.indexKey()] = k++;
				}
			}

			/**
			 * Moves a single record
			 */
			void move(size_t to, size_t from) {
				char buf[SIZE];
				file.seekg(from * SIZE);
				file.read(reinterpret_cast<char*>(buf), SIZE);
				file.seekp(to * SIZE);
				file.write(reinterpret_cast<const char*>(buf), SIZE);
			}

			/**
			 * Shifts down all records one step, starting from and overwriting the record at pos.
			 */
			void shiftDown(size_t pos) {
				const auto N = count() - 1;
				for (auto  k = pos; k < N; ++k) {
					move(k, k+1);
				}
			}

			static void read(fstream& db, size_t pos, Record& r) {
				db.seekg(pos * SIZE);
				db.read(reinterpret_cast<char*>(&r), sizeof(Record));
			}

			static void write(fstream& db, size_t pos, const Record& r) {
				db.seekp(pos * SIZE);
				db.write(reinterpret_cast<const char*>(&r), sizeof(Record));
			}

			void append(fstream& db, const Record& r) {
				db.seekp(0, ios_base::end);
				db.write(reinterpret_cast<const char*>(&r), sizeof(Record));
			}

		public:
			IndexedFile(const string filename, OpenMode mode) : filename{filename} {
				omode = mode;
				file.open(filename, translate(omode));
				if (!file) throw invalid_argument("cannot open " + filename);
			}

			~IndexedFile() = default;
			IndexedFile() = delete;
			IndexedFile(const IndexedFile<Record>&) = delete;
			IndexedFile<Record>& operator=(const IndexedFile<Record>&) = delete;


			size_t size() {
				file.seekg(0, ios_base::end);
				return static_cast<size_t>(file.tellg());
			}

			unsigned count() {
				return this->size() / SIZE;
				//...divide the file-size with the record-size
			}

			/**
			 * Appends a record to the end of the file
			 */
			IndexedFile<Record>& operator<<(const Record& r) {
				if(omode == OpenMode::in)
					throw invalid_argument("file not open for writing");
				append(file, r);


				return *this;
			}

			/**
			 * Used for for-each and operator[]
			 */
			struct iterator {
				fstream&  db;
				size_t    pos;

				iterator(fstream& db, size_t pos) : db{db}, pos{pos} { }

				bool operator!=(const iterator& that) {
					return this->pos < that.pos;
				}

				void operator++() {
					this->pos++;
				}

				Record operator*() {
					Record r;
					read(db, pos, r);
					return r;
				}

				operator Record() {
					return operator*();
				}

				void operator=(const Record& r) {
					write(db, pos, r);
				}
			};

			iterator begin() { return {file, 0}; }
			iterator end()   { return {file, count()}; }


			iterator operator[](size_t pos) {
				if (pos > count()) {
					throw out_of_range("index too large - current size is " + to_string(count()));
				}
				return {file, pos};
			}



			iterator operator[](const string& idx) {
				if (index.empty() && count() > 0) {
					buildIndex();
				}

				if (index.count(idx) == 0) {
					throw out_of_range("no index for " + idx + " found");
				}

				return (*this)[index[idx]];
			}

			void erase(size_t pos) {
				const auto N = count();
				if (N == 0) {
					throw out_of_range("can not erase, database empty");
				}

				if (pos > N) {
					throw out_of_range("index too large - current size is " + to_string(count()));
				}

				shiftDown(pos);

				truncate(filename.c_str(), (N - 1) * SIZE); //adjusts the file size

				index.clear();
			}

			void erase(const string& idx) {
				if (index.empty() && count() > 0) {
					throw out_of_range("can not erase, database empty");
				}

				if (index.count(idx) == 0) {
					throw out_of_range("no index for " + idx + " found");
				}

				erase(index[idx]);
			}

		};
    }

}
