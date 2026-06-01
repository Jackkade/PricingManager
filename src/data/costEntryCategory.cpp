#include "costEntryCategory.h"


CostEntryCategory::CostEntryCategory(string name) {
    setName(name);
}


void CostEntryCategory::setName(std::string name) {
    categoryName = name;
}

std::string CostEntryCategory::getName() {

    return categoryName;
}

void CostEntryCategory::addEntry(CostEntry* e) {
    entries.push_back(e);
}

CostEntry* CostEntryCategory::getEntry(unsigned int at) {

    return entries.at(at);
}

void CostEntryCategory::setEntry(unsigned int at, CostEntry* entry) {
    entries.at(at) = entry;
}

unsigned int CostEntryCategory::getAmount() {
    return entries.size();
}


void CostEntryCategory::swapEntries(CostEntryCategory &other, unsigned int at_one, unsigned int at_two) {
    CostEntry* temp = entries.at(at_one);
    entries.at(at_one) = other.getEntry(at_two);
    other.setEntry(at_two, temp);
}