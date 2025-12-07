#include "linear_search.h"

bool linear_search(const std::vector<int> &haystack, int needle) {
  for (int num : haystack) {
    if (num == needle) {
      return true;
    }
  }

  return false;
}
