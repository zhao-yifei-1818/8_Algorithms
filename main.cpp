#include "helpers.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
void readRegions(vector<Region>& regions)
{
  ifstream file("ZILLOW_REGIONS.csv");
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string id, city, state;
    getline(ss, id, ',');
    getline(ss, city, ',');
    getline(ss, state, ',');
    regions.push_back({stoi(id), city, state});
  }
  file.close();
}

void printFirstFiveRegions(const vector<Region>& regions)
{
  for (int i = 0; i < 5 && i < regions.size(); ++i) {
    const Region& region = regions[i];
    cout << "ID: " << region.id << ", City: " << region.city
         << ", State: " << region.state << endl;
  }
}

int main()
{
  cout << "-----------------------------Part 1----------------------------"
       << endl;
  vector<Region> regions;
  readRegions(regions);

  clock_t start = clock();
  insertionSort(regions);
  clock_t end = clock();
  cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
       << endl;

  cout << "-----------------------------Part 2----------------------------"
       << endl;
  std::vector<Region> regionsByName = regions;
  clock_t start = clock();
  mergeSort(regionsByName);
  clock_t end = clock();
  cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
       << endl;
  printFirstFiveRegions(regions);

  // cout << "-----------------------------Part 3----------------------------"
  //      << endl;
  // cout << "-----------------------------Part 4----------------------------"
  //      << endl;
  // cout << "-----------------------------Part 5----------------------------"
  //      << endl;
  // return 0;
}
