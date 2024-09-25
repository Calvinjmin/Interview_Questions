// Twist with Tracking in Circular Array - [Leetcode 213](https://leetcode.com/problems/house-robber-ii/description/)

using namespace std;

#include <vector>

int rob(vector<int>& nums) {
    // Edge Case -- Cannot take first value automatically
    // dp[0] = rob house 0 or rob house[n-1]
    int n = nums.size();
    if ( n == 1 ) {
    return nums[0];
    }
    if ( n == 2 ) {
    return max(nums[0], nums[1]);
    }

    // three or more houses
    // in the case of three - can take house 1 and 3 or house 2

    // try index 0 to n -2
    // try index 1 to n - 1
    int first = 0;
    int second = 0;

    int t1 = 0, t2 = 0;
    for (int i = 0; i < n - 1; ++i) {
        int temp = t1;
        t1 = max(nums[i] + t2, t1);
        t2 = temp;
    }
    first = t1;

    t1 = 0, t2= 0;
    for (int i = 1; i < n; ++i) {
        int temp = t1;
        t1 = max(nums[i] + t2, t1);
        t2 = temp;
    }
    second = t1;


    return max(first, second);
} 