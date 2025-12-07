#include "binary_search.h"
#include <gtest/gtest.h>
#include <vector>

TEST(binary_search, valid_odd_length_vector) {
  const std::vector<int> haystack = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_TRUE(binary_search(haystack, 6));
}


TEST(binary_search, valid_even_length_vector) {
  const std::vector<int> haystack = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  ASSERT_TRUE(binary_search(haystack, 6));
}

TEST(binary_search, odd_with_needle_in_the_middle) {
  const std::vector<int> haystack = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_TRUE(binary_search(haystack, 5));
}

TEST(binary_search, not_in_vector) {
  const std::vector<int> haystack = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  ASSERT_FALSE(binary_search(haystack, 100));
}

TEST(binary_search, empty_vector) {
  const std::vector<int> haystack = {};

  ASSERT_FALSE(binary_search(haystack, 6));
}

TEST(binary_search, all_0s_vector) {
  const std::vector<int> haystack = {0, 0, 0, 0, 0, 0};

  ASSERT_TRUE(binary_search(haystack, 0));
}

TEST(binary_search, both_positive_negative_numbers) {
  const std::vector<int> haystack = {-2, -1, 0, 1, 2, 3};

  ASSERT_TRUE(binary_search(haystack, 0));
}

TEST(binary_search, all_the_way_to_the_right) {
  const std::vector<int> haystack = {-2, -1, 0, 1, 2, 3};

  ASSERT_TRUE(binary_search(haystack, 3));
}

TEST(binary_search, all_the_way_to_the_left) {
  const std::vector<int> haystack = {-2, -1, 0, 1, 2, 3};

  ASSERT_TRUE(binary_search(haystack, -2));
}
