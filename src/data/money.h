#ifndef MONEY_H
#define MONEY_H
#include <string>
using std::string;

class Money {

    /*|  Constructors  |*/
    
    private:

    /*|  Value  |*/
    unsigned long long mills = 0;        //No Upper Limit // In Mills, or hundreths of a cent. 1$ = 10000. This is done for rounding purposes.
    
    public:
    Money();
    Money(unsigned long long d);
    //Money(string str);        //TODO

    //|  Change Value
    void addMoney(unsigned long long m);
    void subtractMoney(unsigned long long m);
    //|  Operations
    unsigned long long getAmount();

    string getAmountStr();

};

#endif