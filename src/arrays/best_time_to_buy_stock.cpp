#include "best_time_to_buy_stock.h"
#include <algorithm>

int maxProfit(const std::vector<int> &prices) {
  // TODO: Implement your solution here
  //
  // Hint: Track the minimum price seen so far and the maximum profit
  // As you iterate through prices:
  //   1. Update the minimum price if current price is lower
  //   2. Calculate profit if you sold at current price
  //   3. Update maximum profit if current profit is higher
  //
  // Think about it: You want to buy low and sell high
  // So keep track of the lowest price you've seen, and at each step
  // calculate what profit you'd make if you sold at the current price

  if (prices.empty()) {
    return 0;
  }

  int minPrice = prices[0];
  int maxProfit = 0;

  for (size_t i = 1; i < prices.size(); i++) {
    // Update minimum price
    minPrice = std::min(minPrice, prices[i]);

    // Calculate profit if we sell at current price
    int currentProfit = prices[i] - minPrice;

    // Update maximum profit
    maxProfit = std::max(maxProfit, currentProfit);
  }

  return maxProfit;
}
