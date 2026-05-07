#include "costEntry.h"
#include <string>
#include "money.cpp"

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
//  Form:
//  'C82516  ' 17  '--'  'FT'   2.90   0.00   5.00  '--'  0.00  0.00    0.00   0.00 DS_JAMB.SIZ

    string form;
    form = "'" + partID + "' " + std::to_string(supID) + " '" + partColor + "' '" + costUnit + "' " + materialCost.getAmountStr() + " " + laborCost.getAmountStr() + " " + std::to_string(minUnits) + ".00 \n";

    return form;
}
