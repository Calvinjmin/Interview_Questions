// 2D DP with Two Pointer Logic - [Leetcode 647](https://leetcode.com/problems/palindromic-substrings/description/)

#include <vector>

using namespace std;

int countSubstrings(string s) {
    // Palindromic Substring Definition
    // x baab x
    // i      j  
    // if we know str(i+1, j-1) is a palindrome and s[i] == s[j] then that's a palindrome
    
    // dp[i][j] = true if s(i,j) is a palindrome
    int n = s.length();
    int ans = n;
    vector<vector<bool>> dp(n, vector<bool>(n,false));

    // Single Character and Double Character
    for ( int i = 0; i < n; i++ ) {
    dp[i][i] = true;
    }

    // c++ will convert a boolean to a numeric 0 or 1
    for ( int i = 0; i < n -1; i++ ) {
        dp[i][i+1] = (s[i] == s[i+1]);
        ans += dp[i][i+1];
    }

    // length 3 or more
    for ( int len = 3; len <= n; len++ ) {
    for ( int i = 0, j = i + len -1; j < n; i++, j++ ) {
        dp[i][j] = dp[i+1][j-1] && ( s[i] == s[j]);
        ans += dp[i][j];
    }
    }

    return ans;
}