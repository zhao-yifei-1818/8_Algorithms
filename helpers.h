#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

struct Region {
  int id;
  std::string city;
  std::string state;

  bool operator<(const Region& other) const
  {
    return id < other.id;
  }
};

void readRegions(std::vector<Region>& regions);
// void print(const std::vector<Region>& regions);

#endif // HELPERS_H
