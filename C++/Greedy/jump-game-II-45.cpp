// Greedy Choice w/ Tracker - [Leetcode 45](https://leetcode.com/problems/jump-game-ii/description/)

#include <vector>
using namespace std;

int jump(vector<int>& nums) {
    // Thought Process
    // Look at max reach .. if current location is max reach
    // Update the max reach to the current location to nums[i]
    int steps = 0;
    int reach = 0;
    int last = 0;
    for ( int i = 0; i < nums.size() -1 ; i++ ) {
        reach = max( reach, i + nums[i] );
        if ( i == last ) {
            last = reach;
            steps += 1;
        }

    }
    
    return steps;
