#include "helpers.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
Region binaryFind(const std::vector<Region>& regions, int id)
{
  int left = 0;
  int right = regions.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (regions[mid].id == id) {
      return regions[mid];
    } else if (regions[mid].id < id) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  // Return a default Region if not found
  return Region();
}

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
void readPriceRecords(std::vector<PriceRecord>& prices)
{
  std::ifstream file("ZILLOW_DATA.csv");
  std::string line;
  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string regionID, date, value;
    std::getline(ss, regionID, ',');
    std::getline(ss, date, ',');
    std::getline(ss, value, ',');
    prices.push_back({std::stoi(regionID), date, std::stod(value)});
  }
  file.close();
}
void printRecords(const std::vector<PriceRecord>& prices)
{
  for (int i = 0; i < 5; ++i) {
    const PriceRecord& record = prices[i];
    std::cout << "Region ID: " << record.regionID << ", Date: " << record.date
              << ", Value: " << record.value << std::endl;
  }
}

void printFirstFiveRegions(const std::vector<Region>& regions)
{
  for (int i = 0; i < 5; ++i) {
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
  printFirstFiveRegions(regions);

  std::cout << "-----------------------------Part 3----------------------------"
            << std::endl;
  std::vector<Region> regionsByName = regions;
  // clock_t start = clock();
  mergeSort(regionsByName, 0, regionsByName.size() - 1);
  // clock_t end = clock();
  // std::cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
  //           << std::endl;
  printFirstFiveRegions(regionsByName);

  std::cout << "-----------------------------Part 4----------------------------"
            << std::endl;
  std::vector<PriceRecord> prices;
  readPriceRecords(prices);
  printRecords(prices);

  std::cout << "-----------------------------Part 5----------------------------"
            << std::endl;
  Region foundRegion = binaryFind(regions, 20317);
  std::cout << "Found Region: ID: " << foundRegion.id
            << ", City: " << foundRegion.city
            << ", State: " << foundRegion.state << std::endl;

  std::cout << "-----------------------------Part 6----------------------------"
            << std::endl;
  std::string searchCity;
  std::cout << "Enter a city name: ";
  std::getline(std::cin, searchCity);
  clock_t start = clock(); // Start timing
  for (const auto& priceRecord : prices) {
    Region region = binaryFind(regions, priceRecord.regionID);
    if (region.city == searchCity) {
      std::cout << "City: " << region.city << ", State: " << region.state
                << ", Date: " << priceRecord.date
                << ", Value: " << priceRecord.value << std::endl;
    }
  }
  return 0;
}