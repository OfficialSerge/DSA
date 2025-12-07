#include "two_crystal_balls.h"
#include <gtest/gtest.h>
#include <vector>

TEST(two_crystal_balls, valid_input_breaks) {
  const std::vector<bool> breaks = {false, false, false, true, true};

  EXPECT_EQ(two_crystal_balls(breaks), 3);
}

TEST(two_crystal_balls, valid_input_never_breaks_size_2) {
  const std::vector<bool> breaks = {false, false};

  EXPECT_EQ(two_crystal_balls(breaks), -1);
}

TEST(two_crystal_balls, valid_input_breaks_size_2) {
  const std::vector<bool> breaks = {false, true};

  EXPECT_EQ(two_crystal_balls(breaks), 1);
}

TEST(two_crystal_balls, valid_input_never_breaks) {
  const std::vector<bool> breaks = {false, false, false, false, false, false};

  EXPECT_EQ(two_crystal_balls(breaks), -1);
}

TEST(two_crystal_balls, breaks_first_floor) {
  const std::vector<bool> breaks = {true, true, true};

  EXPECT_EQ(two_crystal_balls(breaks), 0);
}

TEST(two_crystal_balls, breaks_last_floor) {
  const std::vector<bool> breaks = {false, false, false, false, false, true};

  EXPECT_EQ(two_crystal_balls(breaks), 5);
}

TEST(two_crystal_balls, empty_vector) {
  const std::vector<bool> breaks = {};

  EXPECT_EQ(two_crystal_balls(breaks), -1);
}
