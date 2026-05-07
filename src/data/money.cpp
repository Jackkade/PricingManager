#include "money.h"
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

    string Money::getAmountStr() {
        string s = std::to_string(mills / 10000) + "." + std::to_string(mills % 10000);
        return s;
    } 