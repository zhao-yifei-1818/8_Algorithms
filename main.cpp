#include "helpers.h"
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
  vector<Region> regions;
  readRegions(regions);
  insertionSort(regions);

  printFirstFiveRegions(regions);
  return 0;
}
