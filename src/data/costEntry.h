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

    /*|  |*/

    public:

    CostEntry(string partID, int supID, string partColor, string costUnit, Money materialCost, Money laborCost, unsigned int minUnits);

    string getStandardForm();

};