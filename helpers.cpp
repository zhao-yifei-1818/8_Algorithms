#include "helpers.h"

void printFirstFiveRegions(const std::vector<Region>& regions)
{
  for (int i = 0; i < 5 && i < regions.size(); ++i) {
    const Region& region = regions[i];
    std::cout << "ID: " << region.id << ", City: " << region.city
              << ", State: " << region.state << std::endl;
  }
}
