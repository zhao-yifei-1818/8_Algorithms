#include "helpers.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
int main()
{
  auto readRegions = [](std::vector<Region>& regions) {
    std::ifstream file("ZILLOW_REGIONS.csv");
    std::string line;
    while (std::getline(file, line)) {
      std::stringstream ss(line);
      std::string id, city, state;
      std::getline(ss, id, ',');
      std::getline(ss, city, ',');
      std::getline(ss, state, ',');
      regions.push_back({std::stoi(id), city, state});
    }
    file.close();
  };

  auto printFirstFiveRegions = [](const std::vector<Region>& regions) {
    for (int i = 0; i < 5 && i < regions.size(); ++i) {
      const Region& region = regions[i];
      std::cout << "ID: " << region.id << ", City: " << region.city
                << ", State: " << region.state << std::endl;
    }
  };

  std::vector<Region> regions;
  readRegions(regions);
  printFirstFiveRegions(regions);

  return 0;
}
