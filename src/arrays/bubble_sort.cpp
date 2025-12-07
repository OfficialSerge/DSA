#include "bubble_sort.h"
#include <utility>
#include <vector>

void bubble_sort(std::vector<int> &input) {
  int size = input.size();

  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - i; j++) {
      if (input[j - 1] > input[j]) {
        std::swap(input[j - 1], input[j]);
      }
    }
  }
}
