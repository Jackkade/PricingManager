#include "money.h"
#include <iostream>
#include <string>

void Money::addMoney(unsigned long long m) {
    mills += m;
}

void Money::subtractMoney(unsigned long long m) {
    mills -= m;
}


unsigned long long Money::getAmount() {
    return mills;
}

string Money::getAmountStr() {// 50.0000


    
    string s = std::to_string(mills / 10000) + "." + std::to_string(mills % 10000);
    return s;
} 

    

Money::Money() {
    mills = 0;
}
Money::Money(unsigned long long d) {
    mills = d;
}
