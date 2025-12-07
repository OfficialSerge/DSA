#ifndef BEST_TIME_TO_BUY_STOCK_H
#define BEST_TIME_TO_BUY_STOCK_H

#include <vector>

/**
 * Best Time to Buy and Sell Stock
 *
 * You are given an array prices where prices[i] is the price of a given stock on the ith day. You
 * want to maximize your profit by choosing a single day to buy one stock and choosing a different
 * day in the future to sell that stock. Return the maximum profit you can achieve from this
 * transaction. If you cannot achieve any profit, return 0.
 */
int maxProfit(const std::vector<int> &prices);

#endif // !BEST_TIME_TO_BUY_STOCK_H
