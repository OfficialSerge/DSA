#include "two_sum.h"
#include <gtest/gtest.h>

// Test basic functionality
TEST(two_sum, basic_input) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = twoSum(nums, target);

  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 1);
}

// Test with negative numbers
TEST(two_sum, negative_values) {
  std::vector<int> nums = {-3, 4, 3, 90};
  int target = 0;
  std::vector<int> result = twoSum(nums, target);

  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 2);
}

// Test with solution at the end
TEST(two_sum, solution_at_end) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  int target = 9;
  std::vector<int> result = twoSum(nums, target);

  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 3);
  EXPECT_EQ(result[1], 4);
}

// Test with duplicate values
TEST(two_sum, duplicate_values) {
  std::vector<int> nums = {3, 3};
  int target = 6;
  std::vector<int> result = twoSum(nums, target);

  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 0);
  EXPECT_EQ(result[1], 1);
}

// Test with larger numbers
TEST(two_sum, large_numbers) {
  std::vector<int> nums = {1000000000, -1000000000, 500000000, 500000000};
  int target = 1000000000;
  std::vector<int> result = twoSum(nums, target);

  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(result[0], 2);
  EXPECT_EQ(result[1], 3);
}
