#include "costEntry.h"
#include <sstream>
#include <string>
#include <vector>
#include "money.cpp"
using std::istringstream;
using std::vector;

CostEntry::CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, unsigned int minUnits) {
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

CostEntry::CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, unsigned int minUnits, string file) {
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
    form = "'" + partID + "' " + std::to_string(supID) + " '" + partColor + "' '" + costUnit + "' " + materialCost.getAmountStr() + " " + laborCost.getAmountStr() + " " + std::to_string(minUnits) + ".00  '--'  0.00  0.00    0.00   0.00 " + file;

    return form;
}


CostEntry::CostEntry(string in) {

    string operand = in;
    std::erase_if(operand, [](unsigned char c) { return (c == '\''); } );

    istringstream stream(operand);
    string datum;
    vector<string> data;
    
    while (stream >> datum) {
        data.push_back(datum);
    }


    /*||||||*/


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

    this->supID = std::stoi(data[1]);

    if (data[2].length() <= 2) {
        this->partColor = data[2];
    }
    else {
        this->partColor = "--";
    }

    if (data[3].length() <= 2) {
        this->costUnit = data[3];
    }
    else {
        this->costUnit = "--";
    }

    this->materialCost = std::stof(data[4]);

    this->laborCost = std::stof(data[5]);

    this->minUnits = std::stoi(data[6]);

    this->file = data[7];

}


string CostEntry::get_PartID() {            return partID;          }
int CostEntry::get_SupID() {                return supID;           }
string CostEntry::get_PartColor() {         return partColor;       }
string CostEntry::get_CostUnit() {          return costUnit;        }
Money CostEntry::get_MaterialCost() {       return materialCost;    }
Money CostEntry::get_LaborCost() {          return laborCost;       }
unsigned int CostEntry::get_MinUnits() {    return minUnits;        }