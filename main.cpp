#include "helpers.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void merge(std::vector<Region>& arr, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  std::vector<Region> L(n1), R(n2);

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] < R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<Region>& arr, int l, int r)
{
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
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
  std::cout << "-----------------------------Part 1----------------------------"
            << std::endl;
  std::vector<Region> regions;
  readRegions(regions);
  printFirstFiveRegions(regions);

  std::cout << "-----------------------------Part 2----------------------------"
            << std::endl;
  // insertionSort(regions);
  // printFirstFiveRegions(regions);

  std::cout << "-----------------------------Part 3----------------------------"
            << std::endl;

  std::vector<Region> regionsByName = regions;
  clock_t start = clock();
  mergeSort(regionsByName, 0, regionsByName.size() - 1);
  clock_t end = clock();
  std::cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
            << std::endl;
  printFirstFiveRegions(regions);

  return 0;
}