// Iterative Dynamic Programming - [Leetcode 91](https://leetcode.com/problems/decode-ways/description)

using namespace std;

#include<vector>

int numDecodings(string s) {
    vector<int> dp(s.length() + 1);
    dp[0] = 1;

    if ( s[0] == '0' ) {
        dp[1] = 0;
    }
    else {
        dp[1] =  1;
    }

    for (int i = 2; i < dp.size(); i++) {
        if (s[i - 1] != '0') {
            dp[i] = dp[i - 1];
        }

        int two_digit = stoi(s.substr(i - 2, 2));
        if (two_digit >= 10 && two_digit <= 26) {
            dp[i] += dp[i - 2];
        }
    }
    return dp[s.length()]; 
} 
