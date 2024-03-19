#include "helpers.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void readRegions(std::vector<Region>& regions)
{
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
}

void printFirstFiveRegions(const std::vector<Region>& regions)
{
  for (int i = 0; i < 5 && i < regions.size(); ++i) {
    const Region& region = regions[i];
    std::cout << "ID: " << region.id << ", City: " << region.city
              << ", State: " << region.state << std::endl;
  }
}

int main()
{
  cout << "-----------------------------Part 1----------------------------"
       << endl;
  vector<Region> regions;
  readRegions(regions);

  cout << "-----------------------------Part 2----------------------------"
       << endl;
  insertionSort(regions);
  cout << "-----------------------------Part 3----------------------------"
       << endl;

  vector<Region> regionsByName = regions;
  clock_t start = clock();
  mergeSort(regionsByName, 0, regionsByName.size() - 1);
  clock_t end = clock();
  cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
       << endl;
  printFirstFiveRegions(regions);

  // cout << "-----------------------------Part 4----------------------------"
  //      << endl;
  // cout << "-----------------------------Part 5----------------------------"
  //      << endl;
  // return 0;
}
