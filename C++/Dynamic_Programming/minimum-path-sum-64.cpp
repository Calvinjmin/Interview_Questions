// 2D Matrix Dynamic Programming - [Leetcode 64](https://leetcode.com/problems/minimum-path-sum/)

using namespace std;

#include <vector>

int minPathSum(vector<vector<int>>& grid) {
    int ROW = grid.size();
    int COL = grid[0].size();
    vector<vector<int>> dp( ROW,vector<int>(COL,0));
    for ( int i = ROW - 1; i >= 0; i-- ) {
        for ( int j = COL - 1; j >= 0; j-- ) {
            if ( i == ROW - 1 && j != COL - 1 ){ // DP from Right
                dp[i][j] = grid[i][j] + dp[i][j+1];
            }
            else if ( i != ROW - 1 && j == COL - 1 ) { // DP from Down
                dp[i][j] = grid[i][j] + dp[i+1][j];
            }
            else if ( i != ROW -1 && j != COL - 1 ) { // Minimum of both
                dp[i][j] = grid[i][j] + min( dp[i+1][j],  dp[i][j+1]);
            }
            else { // First Stage
                dp[i][j] = grid[i][j];
            }
        }
    }
    return dp[0][0];
    
}