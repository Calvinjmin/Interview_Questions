// Using Sorted Stack and Traverse - [Leetcode 962](https://leetcode.com/problems/maximum-width-ramp/description/)

using namespace std;

#include<vector>

int maxWidthRamp(vector<int>& nums) {
    stack<int> s;
    for ( int i = 0; i < nums.size(); i++ ) {
        if ( s.empty() || nums[s.top()] > nums[i] ) {
            s.push(i);
        }
    }

    int ans;
    for ( int j = nums.size() - 1; j > -1; j-- ) {
        while ( !s.empty() && nums[s.top()] <= nums[j] ) {
            ans = max( ans, j - s.top() );
            s.pop();
        }
    }
    return ans;
}
