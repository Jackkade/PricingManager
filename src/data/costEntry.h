#ifndef COSTENTRY_H
#define COSTENTRY_H
#include <string>
using std::string;
#include "money.h"

class CostEntry {


    private:
    
    string partID;                  //MAX 8 Char
    int supID;
    string partColor = "--";        //Max 2 Char
    string costUnit = "--";         //Max 2 Char
    Money materialCost;
    Money laborCost;
    unsigned int minUnits;
    //additionalCost cost;

    string file;
    /*|  |*/

    //Information
    string partName = "";
    string colorDesc = "";
    string description = "";

    /*\|||/*/

    public:

    CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, unsigned int minUnits);
    CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, unsigned int minUnits, string f);
    CostEntry(string in);   //From Read String
    string getStandardForm();


    string get_PartID();
    int get_SupID();
    string get_PartColor();
    string get_CostUnit();
    Money get_MaterialCost();
    Money get_LaborCost();
    unsigned int get_MinUnits();
    string get_file();

    bool set_PartID(string);
    bool set_SupID(int);
    bool set_PartColor(string);
    bool set_CostUnit(string);
    bool set_MaterialCost(Money);
    bool set_LaborCost(Money);
    bool set_MinUnits(unsigned int);
    bool set_file(string);

    string get_PartName();
    string get_ColorDesc();
    string get_Description();
    
    bool set_PartName(string input);
    bool set_ColorDesc(string input);
    bool set_Description(string input);
};

#endif