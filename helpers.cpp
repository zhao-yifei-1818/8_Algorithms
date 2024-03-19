#include "helpers.h"

std::vector<Region> slice(const std::vector<Region>& vec, size_t startLoc,
                          size_t endLoc)
{
  std::vector<Region> newVec;
  for (size_t i = startLoc; i < endLoc; ++i) {
    newVec.push_back(vec.at(i));
  }
  return newVec;
}

std::vector<Region> merge(const std::vector<Region>& vec1,
                          const std::vector<Region>& vec2)
{
  std::vector<Region> newVec;
  size_t i = 0, j = 0;
  while (i < vec1.size() && j < vec2.size()) {
    if (vec1.at(i) < vec2.at(j)) {
      newVec.push_back(vec1.at(i++));
    } else {
      newVec.push_back(vec2.at(j++));
    }
  }
  while (i < vec1.size()) {
    newVec.push_back(vec1.at(i++));
  }
  while (j < vec2.size()) {
    newVec.push_back(vec2.at(j++));
  }
  return newVec;
}

void mergeSort(std::vector<Region>& vec)
{
  if (vec.size() > 1) {
    size_t mid = vec.size() / 2;
    std::vector<Region> left = slice(vec, 0, mid);
    std::vector<Region> right = slice(vec, mid, vec.size());

    mergeSort(left);
    mergeSort(right);

    vec = merge(left, right);
  }
}
