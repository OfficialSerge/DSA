#include "linear_search.h"
#include <gtest/gtest.h>

TEST(linear_search, valid_int_input) {
  const std::vector<int> haystack = {1, 2, 3, 4, 5, 6, 7};

  EXPECT_TRUE(linear_search(haystack, 2));
}

TEST(linear_search, empty_vector_input) {
  const std::vector<int> haystack = {};

  EXPECT_FALSE(linear_search(haystack, 2));
}

TEST(linear_search, value_not_in_vector) {
  const std::vector<int> haystack = {1, 2, 3, 4, 5};

  EXPECT_FALSE(linear_search(haystack, 12));
}

TEST(linear_search, all_0s_vector) {
  const std::vector<int> haystack = {0, 0, 0, 0, 0, 0, 0};

  EXPECT_TRUE(linear_search(haystack, 0));
}

TEST(linear_search, all_1s_vector) {
  const std::vector<int> haystack = {1, 1, 1, 1, 1, 1, 1};

  EXPECT_TRUE(linear_search(haystack, 1));
}
