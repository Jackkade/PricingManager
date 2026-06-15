#ifndef COSTENTRY_CPP
#define COSTENTRY_CPP

#include "costEntry.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm> 
#include "money.cpp"
using std::istringstream;
using std::vector;

CostEntry::CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, float minUnits) {
    if (partID.length() > 8) {
        partID.erase(8);
        this->partID = partID;
    }
    else if (partID.length() < 8) {
        partID.resize(8, ' ');
        this->partID = partID;
    }
    else {
        this->partID = partID;
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

    this->file = "";
}

CostEntry::CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, float minUnits, string file) {
    if (partID.length() > 8) {
        partID.erase(8);
        this->partID = partID;
    }
    else if (partID.length() < 8) {
        partID.resize(8, ' ');
        this->partID = partID;
    }
    else {
        this->partID = partID;
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

    this->file = file;
}

string CostEntry::getStandardForm() {
//  Form:
//  'C82516  ' 17  '--'  'FT'   2.90   0.00   5.00  '--'  0.00  0.00    0.00   0.00 DS_JAMB.SIZ

    string form;
    form = "'" + partID + "' " + std::to_string(supID) + " '" + partColor + "' '" + costUnit + "' " + materialCost.getAmountStr() + " " + laborCost.getAmountStr() + " " + std::to_string(minUnits) + "  '--'  0.00  0.00    0.00   0.00 " + file;

    return form;
}


CostEntry::CostEntry(string in) {

    string operand = in;
    std::replace(operand.begin(), operand.end(), '\'', ' ');


    std::cout << operand << '\n';
    istringstream stream(operand);
    string datum;
    vector<string> data;
    
    while (stream >> datum) {
        data.push_back(datum);
    }

    /*||||||*/


    std::cout << data[0] << '\n';
    if (data[0].length() > 8) {

        data[0].erase(8);
        this->partID = data[0];
    }
    else if (data[0].length() < 8) {

        data[0].resize(8, ' ');
        this->partID = data[0];
    }
    else {

        this->partID = data[0];
    }

    std::cout << data[1] << '\n';

    this->supID = std::stoi(data[1]);

    std::cout << data[2] << '\n';
    if (data[2].length() <= 2) {

        this->partColor = data[2];
    }
    else {
        this->partColor = "--";
    }

    std::cout << data[3] << '\n';

    if (data[3].length() <= 2) {
        this->costUnit = data[3];
    }
    else {
        this->costUnit = "--";
    }

    std::cout << data[4] << '\n';
    this->materialCost = std::stof(data[4]) * 10000;

    std::cout << data[5] << '\n';
    this->laborCost = std::stof(data[5]) * 10000;

    std::cout << data[6] << '\n';
    this->minUnits = std::stof(data[6]);

    if(data.size() == 13 ) {
        std::cout << data[12] << '\n';
        this->file = data[12];

    }
    else { 
        this->file = ""; 
    }

}


string CostEntry::get_PartID() {            return partID;          }
int CostEntry::get_SupID() {                return supID;           }
string CostEntry::get_PartColor() {         return partColor;       }
string CostEntry::get_CostUnit() {          return costUnit;        }
Money CostEntry::get_MaterialCost() {       return materialCost;    }
Money CostEntry::get_LaborCost() {          return laborCost;       }
float CostEntry::get_MinUnits() {    return minUnits;        }
string CostEntry::get_file() {              return file;            }


bool CostEntry::set_PartID(string partID) {
    bool successful = true;
    if (partID.length() > 8) {
        partID.erase(8);
        this->partID = partID;
    }
    else if (partID.length() < 8) {
        partID.resize(8, ' ');
        this->partID = partID;
    }
    else {
        this->partID = partID;
    }

    return successful;
}
bool CostEntry::set_SupID(int supID) {
    bool successful = true;

    this->supID = supID;

    return successful;
}
bool CostEntry::set_PartColor(string partColor) {
    bool successful = true;

    if (partColor.length() <= 2) {
        this->partColor = partColor;
    }
    else {
        this->partColor = "--";
        successful = false;
    }

    return successful;
}
bool CostEntry::set_CostUnit(string costUnit) {
    bool successful = true;

    if (costUnit.length() <= 2) {
        this->costUnit = costUnit;
    }
    else {
        this->costUnit = "--";
        successful = false;
    }

    return successful;
}
bool CostEntry::set_MaterialCost(Money materialCost) {
    bool successful = true;

    this->materialCost = materialCost;

    return successful;
}
bool CostEntry::set_LaborCost(Money laborCost) {
    bool successful = true;

    this->laborCost = laborCost;

    return successful;
}
bool CostEntry::set_MinUnits(float minUnits) {
    bool successful = true;

    this->minUnits = minUnits;

    return successful;
}
bool CostEntry::set_file(string file) {
    bool successful = true;

    this->file = file;

    return successful;
}



string CostEntry::get_PartName() {
    return partName;
}
string CostEntry::get_ColorDesc() {
    return colorDesc;
}
string CostEntry::get_Description() {
    return description;
}
    
bool CostEntry::set_PartName(string input) {
    partName = input;
    return true;
}
bool CostEntry::set_ColorDesc(string input) {
    colorDesc = input;
    return true;

}
bool CostEntry::set_Description(string input) {
    description = input;
    return true;

}

#endif