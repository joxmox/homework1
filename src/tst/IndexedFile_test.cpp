#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "text.hpp"
#include "IndexedFile.hpp"

using namespace std;
using NNN::IndexedFile;
using NNN::OpenMode;
using NNN::text;

class Person {
    text<10> name{"Anna Conda"};
    unsigned age{42};

public:
    Person() = default;
    Person(const string& name, unsigned age) : name(name), age(age) { }

    string toString() const {
        //...
    }

    //...

    string indexKey() const {
        //...
    }
};

ostream& operator<<(ostream& os, const Person& p) {
    //...
}


const string dbname = "persons.db";

void rm(const string f) {
    string cmd = "rm -f ";
    cmd += f;
    system(cmd.c_str());
}


void insert_one_record_should_give_count_of_one() {
    rm(dbname);
    IndexedFile<Person> f{dbname, OpenMode::out};

    assert(f.size() == 0);
    assert(f.count() == 0);

    Person p;
    f << p;
    assert(f.size() == sizeof(Person));
    assert(f.count() == 1);
}

void insert_three_records_should_give_count_of_three() {
    rm(dbname);

    Person p1{"Anna", 10};
    Person p2{"Berit", 20};
    Person p3{"carin", 30};

    IndexedFile<Person> db{dbname, OpenMode::out};
    //...

    assert(db.size() == 3 * sizeof(Person));
    assert(db.count() == 3);
}

/**
 * Helper: store N persons
 */
void store_persons(unsigned N) {
    IndexedFile<Person> db{dbname, OpenMode::out};

    for (unsigned k = 1; k <= N; ++k) {
        Person p{"Person-" + to_string(k), 10 * k};
        db << p;
    }

    assert(db.count() == N);
}

void insert_many_records_and_read_by_foreach_should_pass() {
    rm(dbname);
    unsigned N = 500;
    store_persons(N);

    IndexedFile<Person> db{dbname, OpenMode::in};
    assert(db.count() == N);

    unsigned  k = 1;
    for (/* ... */) {
        assert(p.getAge() == 10 * k);
        assert(p.getName() == "Person-" + to_string(k));
        ++k;
    }
}

void read_by_index_op_within_bounds_should_pass() {
    rm(dbname);
    unsigned N = 500;
    store_persons(N);

    IndexedFile<Person> db{dbname, OpenMode::in};
    for (unsigned k = 1; k <= N; ++k) {
        //...
    }
}

void readwrite_by_index_op_should_pass() {
    rm(dbname);
    unsigned N = 5;
    store_persons(N);

    {
        //...open db and modify each record
    }

    {
        //...open db and verify all records have changed
    }
}

void read_by_index_op_outside_bounds_should_throw() {
    rm(dbname);
    unsigned N = 5;
    store_persons(N);

    try {
        //...use [] outside bounds and assert(false) to catch non-throws
    } catch (out_of_range& x) {
        assert(string(x.what()).substr(0, 11) == "operator[]:");
    }
}

void read_by_index_op_using_indexkey_should_pass() {
    rm(dbname);
    unsigned N            = 5;
    store_persons(N);

    IndexedFile<Person> db{dbname, OpenMode::in};
    for (unsigned       k = 1; k <= N; ++k) {
        string name = "Person-" + to_string(k);
        //...index by name and verify
    }
}

void read_by_indexkey_with_unknown_should_throw() {
    rm(dbname);
    unsigned N = 5;
    store_persons(N);

    try {
        //...index with invalid key, don't forget assert(false)
    } catch (out_of_range& x) {
        assert(string(x.what()).substr(0, 11) == "operator[]:");
    }
}

void readwrite_using_indexkey_should_pass() {
    rm(dbname);
    unsigned N = 5;
    store_persons(N);

    {
        //...read by index-key and modify each record
    }

    {
        //verify
    }
}

void erase_records_should_work() {
    rm(dbname);
    unsigned N            = 50;
    store_persons(N);

    IndexedFile<Person> db{dbname, OpenMode::inout};
    for (unsigned       k = 1; k <= N; ++k) {
        //...delete the first record
        assert(db.count() == (N - k));

        if (k < N) {
            //...read the (now) first record and verify its the previous second record
        }
    }
}

//...

int main(int numArgs, char* args[]) {
    insert_one_record_should_give_count_of_one();
    //...

    rm(dbname);
    cout << "All tests passed\n";
    return 0;
}
