#include <gtest/gtest.h>
#include <optional>
#include "queue.h"

TEST(queue, enqueue) {
  Queue<int> q;
  ASSERT_EQ(q.size(), 0);

  q.enqueue(5);
  ASSERT_EQ(q.size(), 1);
  q.enqueue(10);
  ASSERT_EQ(q.size(), 2);
  q.enqueue(15);
  ASSERT_EQ(q.size(), 3);
}

TEST(queue, dequeue_non_empty) {
  Queue<int> q;

  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);

  EXPECT_EQ(q.deque(), 1);
  EXPECT_EQ(q.deque(), 2);
  EXPECT_EQ(q.deque(), 3);
  EXPECT_EQ(q.deque(), 4);
}

TEST(queue, dequeue_empty) {
  Queue<int> q;
  EXPECT_EQ(q.deque(), std::nullopt);
}

TEST(queue, peek_non_empty) {
  Queue<int> q;

  q.enqueue(1);
  EXPECT_EQ(q.peek(), 1);
  q.enqueue(2);
  EXPECT_EQ(q.peek(), 1);
  q.deque(); 
  EXPECT_EQ(q.peek(), 2);
}

TEST(queue, peek_empty) {
  Queue<int> q;
  EXPECT_EQ(q.peek(), std::nullopt);
}

TEST(queue, size) {
  Queue<int> q;
  EXPECT_EQ(q.size(), 0);

  q.enqueue(1);
  EXPECT_EQ(q.size(), 1);
  q.enqueue(2);
  EXPECT_EQ(q.size(), 2);
  q.enqueue(3);
  EXPECT_EQ(q.size(), 3);
  q.enqueue(4);
  EXPECT_EQ(q.size(), 4);
}
