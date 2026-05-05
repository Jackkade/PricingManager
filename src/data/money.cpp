#include "money.h"

    void Money::addMoney(unsigned long long m) {
        mills += m;
    }

    void Money::subtractMoney(unsigned long long m) {
        mills -= m;
    }

    unsigned long long Money::getAmount() {
        return mills;
    }