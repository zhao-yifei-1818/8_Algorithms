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

template<typename T>
void insertionSort(std::vector<T>& vec)
{
  for (size_t i = 1; i < vec.size(); ++i) {
    T key = vec[i];
    size_t j = i;
    while (j > 0 && key < vec[j - 1]) {
      vec[j] = vec[j - 1];
      --j;
    }
    vec[j] = key;
  }
}
void merge(std::vector<Region>& arr, int l, int m, int r);
void mergeSort(std::vector<Region>& arr, int l, int r);
#endif // HELPERS_H
