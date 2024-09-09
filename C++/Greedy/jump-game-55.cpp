// Greedy Choice - [Leetcode 55](https://leetcode.com/problems/jump-game/description/)

#include <vector>
using namespace std;

/*
    Greedy Choice -> Take the fartest jump and see if it reaches the end
*/
bool canJump(vector<int>& nums) {
    int loc = 0;
    int n = nums.size();
    for ( int i =0; i < n; i++ ) {
        if ( loc < i || loc >= n - 1 ) {
            break;
        }
        loc = max(loc, i + nums[i]);
    }
    return loc >= n - 1;
}