

class Money {

    /*|  Constructors  |*/
    Money();
    Money(unsigned long long d);
    Money(unsigned long long d, unsigned short c);
    Money(unsigned long long d, unsigned short c, unsigned short m);

    private:


    /*|  Value  |*/
    unsigned long long dollars = 0;        //No Upper Limit
    unsigned short cents = 0;          //Max 99
    unsigned short mills = 0;          //Max 99

    public:

    //|  Change Value
    void addDollars(unsigned int d);
    void subtractDollars(unsigned int d);
    
    void addCents(unsigned int d);
    void subtractCents(unsigned int d);
    
    void addMills(unsigned int d);
    void subtractMills(unsigned int d);
    
    //|  Operations
    void multiplyAmount(int n);

};