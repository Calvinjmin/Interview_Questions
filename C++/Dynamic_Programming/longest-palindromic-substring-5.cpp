// Two Pointer with Dynamic Programming - [Leetcode 5](https://leetcode.com/problems/different-ways-to-add-parentheses)

// Time - O(n^2)
// Space - O(n^2)

using namespace std;

#include<vector>

string longestPalindrome(string s) {
    // create a dp of the current string to see if that inner parts of it are palindromic
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int ans[2] = {0,0};

    // same letter is always palindromic
    for ( int i = 0; i < n; i++ ) {
        dp[i][i] = true;
    }

    for ( int i = 0; i < n -1; i++ ) {
        if ( s[i] == s[i+1] ) {
            dp[i][i+1] = true;
            ans[0] = i;
            ans[1] = i + 1;
        }
    }

    for (int diff = 2; diff < n; ++diff) {
        for (int i = 0; i < n - diff; ++i) {
            int j = i + diff;
            // need i and i+1 in dp already
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans[0] = i;
                ans[1] = j;
            }
        }
    }

    return s.substr( ans[0], ans[1] - ans[0] + 1 );
}
