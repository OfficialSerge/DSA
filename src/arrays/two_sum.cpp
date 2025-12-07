#include "two_sum.h"
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int> &nums, int target) {
  std::unordered_map<int, int> seen;

  for (int i = 0; i < static_cast<int>(nums.size()); i++) {
    int complement = target - nums[i];

    if (seen.find(complement) != seen.end()) {
      return {seen[complement], i};
    }

    seen[nums[i]] = i;
  }

  return {}; 
}
