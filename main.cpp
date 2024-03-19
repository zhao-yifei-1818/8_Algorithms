#include "helpers.h"
#include <vector>

int main()
{
  std::vector<Region> regions;
  readRegions(regions);
  printFirstFiveRegions(regions);
  return 0;
}
