#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

struct Region {
  int id;
  std::string city;
  std::string state;
};

void readRegions(std::vector<Region>& regions);
void printFirstFiveRegions(const std::vector<Region>& regions);

#endif // HELPERS_H
