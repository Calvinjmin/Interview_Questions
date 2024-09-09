// Sliding Window w/ Running Counter - [Leetcode 208](https://leetcode.com/problems/minimum-size-subarray-sum/description/)
using namespace std;

#include <vector>

int minSubArrayLen(int target, vector<int>& nums) {
    int count = 0;
    int left = 0;
    int ans = nums.size() + 1;
    for ( int r = 0; r < nums.size(); r++ ) {
        count += nums[r];
        while ( count >= target ) {
            count -= nums[left];
            ans = min(ans, r - left + 1 );
            left += 1;
        }

    }
    if ( ans == nums.size() + 1) {
        return 0;
    }
    return ans;
}