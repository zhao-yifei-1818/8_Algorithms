#include "helpers.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
Region binaryFind(const vector<Region>& regions, int id)
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

void merge(vector<Region>& arr, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  vector<Region> L(n1), R(n2);

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

void mergeSort(vector<Region>& arr, int l, int r)
{
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}
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
void readPriceRecords(vector<PriceRecord>& prices)
{
  ifstream file("ZILLOW_DATA.csv");
  string line;
  while (getline(file, line)) {
    stringstream ss(line);
    string regionID, date, value;
    getline(ss, regionID, ',');
    getline(ss, date, ',');
    getline(ss, value, ',');
    prices.push_back({stoi(regionID), date, stod(value)});
  }
  file.close();
}
void printRecords(const vector<PriceRecord>& prices)
{
  for (int i = 0; i < 5; ++i) {
    const PriceRecord& record = prices[i];
    cout << "Region ID: " << record.regionID << ", Date: " << record.date
         << ", Value: " << record.value << endl;
  }
}

void printFirstFiveRegions(const vector<Region>& regions)
{
  for (int i = 0; i < 5; ++i) {
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
  printFirstFiveRegions(regions);

  cout << "-----------------------------Part 2----------------------------"
       << endl;
  // insertionSort(regions);
  printFirstFiveRegions(regions);

  cout << "-----------------------------Part 3----------------------------"
       << endl;
  vector<Region> regionsByName = regions;
  // clock_t start = clock();
  mergeSort(regionsByName, 0, regionsByName.size() - 1);
  // clock_t end = clock();
  // cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
  //           << endl;
  printFirstFiveRegions(regionsByName);

  cout << "-----------------------------Part 4----------------------------"
       << endl;
  vector<PriceRecord> prices;
  readPriceRecords(prices);
  printRecords(prices);

  cout << "-----------------------------Part 5----------------------------"
       << endl;
  Region foundRegion = binaryFind(regions, 20317);
  cout << "Found Region: ID: " << foundRegion.id
       << ", City: " << foundRegion.city << ", State: " << foundRegion.state
       << endl;

  cout << "-----------------------------Part 6----------------------------"
       << endl;
  string searchCity;
  cout << "Enter a city name: ";
  getline(cin, searchCity);
  clock_t start = clock();
  for (const auto& priceRecord : prices) {
    Region region = binaryFind(regions, priceRecord.regionID);
    if (region.city == searchCity) {
      cout << "City: " << region.city << ", State: " << region.state
           << ", Date: " << priceRecord.date << ", Value: " << priceRecord.value
           << endl;
    }
  }
  clock_t end = clock();
  cout << "Took " << 1.0 * (end - start) / CLOCKS_PER_SEC << " seconds."
       << endl;
  return 0;
}