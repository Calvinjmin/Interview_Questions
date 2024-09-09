// Bottom Up DP - [Leetcode 322](https://leetcode.com/problems/coin-change/description/)

#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp( amount + 1, amount + 1 );
    dp[0] = 0;
    for ( int i = 0; i <= amount; i++ ) {
        for ( int c: coins ) {
            if ( i - c >= 0 ) {
                dp[i] = min( dp[i] , 1 + dp[i-c] );
            }
        }
    }
    if ( dp[amount] == amount + 1 ) {
        return -1;
    }
    return dp[amount];
}