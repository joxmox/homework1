


template<size_t N, unsigned byte D>
class real {
    char payload[N];


  public:
    real() {
        //...
    }
    real(float v) {
        //...
    }
    
    float value() const {
        //...
    }
    void value(float v) {
    
    }
    
    operator float() const {return value();}
    real<N,D>&  operator=(float v) {value(v); return *this;}

    //...
};

//...


