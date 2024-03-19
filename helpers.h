#ifndef HELPERS_H
#define HELPERS_H

#include <string>
#include <vector>

using namespace std;
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
  for (int i = 1; i < vec.size(); ++i) {
    T key = vec[i];
    int j = i;
    while (j > 0 && key < vec[j - 1]) {
      vec[j] = vec[j - 1];
      --j;
    }
    vec[j] = key;
  }
}

#endif // HELPERS_H
