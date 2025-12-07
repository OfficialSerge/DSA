#include "stack.h"
#include <gtest/gtest.h>
#include <optional>

TEST(stack, push) {
  Stack<int> s;
  ASSERT_EQ(s.size(), 0);

  s.push(1);
  ASSERT_EQ(s.size(), 1);
  s.push(2);
  ASSERT_EQ(s.size(), 2);
  s.push(3);
  ASSERT_EQ(s.size(), 3);
}

TEST(stack, pop) {
  Stack<int> s;
  EXPECT_EQ(s.pop(), std::nullopt);

  s.push(1);
  s.push(2);
  s.push(3);

  EXPECT_EQ(s.pop(), 3);
  EXPECT_EQ(s.pop(), 2);
  EXPECT_EQ(s.pop(), 1);
  EXPECT_EQ(s.pop(), std::nullopt);
}

TEST(stack, peek) {
  Stack<int> s;
  EXPECT_EQ(s.peek(), std::nullopt);

  s.push(11);
  EXPECT_EQ(s.peek(), 11);
  s.push(8);
  EXPECT_EQ(s.peek(), 8);
  s.push(70);
  EXPECT_EQ(s.peek(), 70);
}
