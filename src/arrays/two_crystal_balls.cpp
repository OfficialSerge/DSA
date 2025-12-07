#include "two_crystal_balls.h"
#include <cmath>
#include <sys/types.h>

int two_crystal_balls(const std::vector<bool> &breaks) {
  int floor = 0;
  int size = breaks.size();
  int step = std::sqrt(breaks.size());

  for (; floor < size; floor += step) {
    if (breaks[floor])
      break;
  }

  floor = std::max(floor - step, 0);

  for (; floor < size; ++floor) {
    if (breaks[floor])
      return floor;
  }

  return -1;
}
