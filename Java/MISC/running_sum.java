/*
LEETCODE PROBLEM: https://leetcode.com/problems/running-sum-of-1d-array/

Description: Return the running sum of the given array

Basic Solution: Create a mirrored array, and iterate the given array to solve
                    the running solution.
 */

class Solution {
    public int[] runningSum(int[] nums) {
        int[]ans = new int[nums.length];
        ans[0] = nums[0];
        for ( int i = 1; i < nums.length; i++ ) {
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
}