#ifndef COSTENTRYCATEGORY_H
#define COSTENTRYCATEGORY_H

#include <vector>
#include "costEntry.h"

class CostEntryCategory {
    private:
    std::string categoryName;
    std::vector<CostEntry> entries;
    
    public:
    void setName(std::string name);
    std::string getName();

    void addEntry(CostEntry e);
    CostEntry getEntry(unsigned int at);
    void swapEntries(std::vector<CostEntry> &other, unsigned int at_one, unsigned int at_two);
};

#endif