/*
LEETCODE PROBLEM: https://leetcode.com/problems/richest-customer-wealth/

Description: Given a 2D array, return the maximum wealth, given that each entry
                is a person and their array is their numerical wealth.

Basic Solution: Iterate through the 2D array, calculate each person's wealth
                    and compare to a "temp" maxWealth variable.
 */

class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        int temp;
        for ( int i = 0; i < accounts.length; i++ ) {
            temp = 0;
            for ( int j = 0; j < accounts[i].length; j++ ) {
                temp += accounts[i][j];
            }
            if ( temp > maxWealth ) {
                maxWealth = temp;
            }
        }
        return maxWealth;
    }
}