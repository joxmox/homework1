

class boolean {
    char  payload;
    constexpr static char FALSE = 'F';
    constexpr static char TRUE  = 'T';

  public:
    boolean() { payload = FALSE; }
    boolean(bool v)  {}
    
    bool value() const {
        return payload == TRUE;
    }
    void value(bool v) {
        payload = (v ? TRUE : FALSE);
    }

    operator bool() const {return value();}
    boolean&  operator=(bool v) {value(v);}

    //...
};

//...

