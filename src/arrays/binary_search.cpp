#include "binary_search.h"

bool binary_search(const std::vector<int> &haystack, int needle) {
  int lo = 0;
  int hi = haystack.size() - 1;

  while (lo <= hi) {
    int middle = (lo + hi) >> 1;
    const int value = haystack[middle];

    if (value == needle) {
      return true;
    } else if (needle < value) {
      hi = middle;
    } else {
      lo = middle + 1;
    }
  }

  return false;
}
