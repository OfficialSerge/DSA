#include "best_time_to_buy_stock.h"
#include <gtest/gtest.h>

// Test example 1 from problem description
TEST(BestTimeToBuyStockTest, Example1) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(maxProfit(prices), 5);
}

// Test example 2 - no profit possible
TEST(BestTimeToBuyStockTest, Example2_NoProfitPossible) {
  std::vector<int> prices = {7, 6, 4, 3, 1};
  EXPECT_EQ(maxProfit(prices), 0);
}

// Test single element
TEST(BestTimeToBuyStockTest, SingleElement) {
  std::vector<int> prices = {5};
  EXPECT_EQ(maxProfit(prices), 0);
}

// Test two elements - profit possible
TEST(BestTimeToBuyStockTest, TwoElements_Profit) {
  std::vector<int> prices = {1, 5};
  EXPECT_EQ(maxProfit(prices), 4);
}

// Test two elements - no profit
TEST(BestTimeToBuyStockTest, TwoElements_NoProfit) {
  std::vector<int> prices = {5, 1};
  EXPECT_EQ(maxProfit(prices), 0);
}

// Test all same prices
TEST(BestTimeToBuyStockTest, AllSamePrices) {
  std::vector<int> prices = {3, 3, 3, 3, 3};
  EXPECT_EQ(maxProfit(prices), 0);
}

// Test maximum profit at the end
TEST(BestTimeToBuyStockTest, MaxProfitAtEnd) {
  std::vector<int> prices = {1, 2, 3, 4, 5};
  EXPECT_EQ(maxProfit(prices), 4);
}

// Test with zeros
TEST(BestTimeToBuyStockTest, WithZeros) {
  std::vector<int> prices = {0, 6, 3, 2, 8};
  EXPECT_EQ(maxProfit(prices), 8);
}

// Test large gap
TEST(BestTimeToBuyStockTest, LargeGap) {
  std::vector<int> prices = {10000, 1, 9999};
  EXPECT_EQ(maxProfit(prices), 9998);
}
