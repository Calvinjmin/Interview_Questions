/*
    LeetCode Question 198
    House Robber
*/

#include <vector>

using namespace std;

int rob(vector<int> &nums) {
  int n = nums.size();
  vector<int> dp(n, 0);

  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return nums[0];
  }
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  // Dynamnic Programming
  // Either rob the current house and the sum of the house twice before
  //        or take the sum of the previous house
  for (int i = 2; i < n; i++) {
    dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
  }

  // The last slot in the DP vector should return the max value
  return dp[n - 1];
}