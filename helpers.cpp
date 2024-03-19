#include "helpers.h"
using namespace std;

vector<Region> slice(const vector<Region>& vec, size_t startLoc, size_t endLoc)
{
  vector<Region> newVec;
  for (size_t i = startLoc; i < endLoc; ++i) {
    newVec.push_back(vec.at(i));
  }
  return newVec;
}

vector<Region> merge(const vector<Region>& vec1, const vector<Region>& vec2)
{
  vector<Region> newVec;
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

void mergeSort(vector<Region>& vec)
{
  if (vec.size() > 1) {
    size_t mid = vec.size() / 2;
    vector<Region> left = slice(vec, 0, mid);
    vector<Region> right = slice(vec, mid, vec.size());

    mergeSort(left);
    mergeSort(right);

    vec = merge(left, right);
  }
}
