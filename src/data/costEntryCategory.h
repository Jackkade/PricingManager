#pragma once
#include <vector>
#include "costEntry.h"

class CostEntryCategory {
    private:
    std::string categoryName;
    std::vector<CostEntry*> entries;

    void setEntry(unsigned int at, CostEntry* entry);   //WARNING!! LEAKS MEMORY UNLESS REASSIGNED ELSEWHERE

    public:

    CostEntryCategory(string name);

    void setName(std::string name);
    std::string getName();

    void addEntry(CostEntry* e);
    CostEntry* getEntry(unsigned int at);
    unsigned int getAmount();
    void swapEntries(CostEntryCategory &other, unsigned int at_one, unsigned int at_two);
};