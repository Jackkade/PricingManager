#include "costEntry.h"

CostEntry::CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, unsigned int minUnits) {
    if (partID.length() <= 8) {
        this->partID = partID;
    }
    else {
        this->partID = "";
    }

    this->supID = supID;

    if (partColor.length() <= 2) {
        this->partColor = partColor;
    }
    else {
        this->partColor = "--";
    }

    if (costUnit.length() <= 2) {
        this->costUnit = costUnit;
    }
    else {
        this->costUnit = "--";
    }

    this->materialCost = materialCost;

    this->laborCost = laborCost;

    this->minUnits = minUnits;
}

string CostEntry::getStandardForm() {
    return "";
}
