// #include "helpers.h"
// Region binaryFind(const std::vector<Region>& regions, int id)
// {
//   int left = 0;
//   int right = regions.size() - 1;

//   while (left <= right) {
//     int mid = left + (right - left) / 2;
//     if (regions[mid].id == id) {
//       return regions[mid];
//     } else if (regions[mid].id < id) {
//       left = mid + 1;
//     } else {
//       right = mid - 1;
//     }
//   }
//   // Return a default Region if not found
//   return Region();
// }
// why linking .cpp and .h been not working