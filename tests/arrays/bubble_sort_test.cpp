#include "bubble_sort.h"
#include <gtest/gtest.h>
#include <vector>

TEST(bubble_sort, unsorted_array) {
  std::vector<int> input = {2, 3, 11, 7, -1, 0, 2, 3};
  std::vector<int> output = {-1, 0, 2, 2, 3, 3, 7, 11};

  bubble_sort(input);
  EXPECT_EQ(input, output);
}

TEST(bubble_sort, all_negatives) {
  std::vector<int> input = {-1, -2, -3, -4, -5};
  std::vector<int> output = {-5, -4, -3, -2, -1};

  bubble_sort(input);
  EXPECT_EQ(input, output);
}

TEST(bubble_sort, one_item) {
  std::vector<int> input = {2};
  std::vector<int> output = {2};

  bubble_sort(input);
  EXPECT_EQ(input, output);
}

TEST(bubble_sort, no_items) {
  std::vector<int> input = {};
  std::vector<int> output = {};

  bubble_sort(input);
  EXPECT_EQ(input, output);
}

TEST(bubble_sort, all_same_value) {
  std::vector<int> input = {3, 3, 3, 3};
  std::vector<int> output = {3, 3, 3, 3};

  bubble_sort(input);
  EXPECT_EQ(input, output);
}

TEST(bubble_sort, already_sorted) {
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> output = {1, 2, 3, 4, 5};

  bubble_sort(input);
  EXPECT_EQ(input, output);
}
