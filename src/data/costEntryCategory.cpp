#include "costEntryCategory.h"


void CostEntryCategory::setName(std::string name) {
    categoryName = name;
}

std::string CostEntryCategory::getName() {
    return categoryName;
}

void CostEntryCategory::addEntry(CostEntry e) {
    entries.push_back(e);
}

CostEntry CostEntryCategory::getEntry(unsigned int at) {
    return entries.at(at);
}

void CostEntryCategory::swapEntries(std::vector<CostEntry> &other, unsigned int at_one, unsigned int at_two) {
    CostEntry temp = entries.at(at_one);
    entries.at(at_one) = other.at(at_two);
    other.at(at_two) = temp;
}