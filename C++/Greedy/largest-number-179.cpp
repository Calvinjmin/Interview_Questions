// Greedy Choice with sorting based on string concatenation - [Leetcode 179](https://leetcode.com/problems/largest-number/description/)

using namespace std;

#include <vector>

string largestNumber(vector<int>& nums) {
    vector<string> numStr;
    for ( int n : nums ) {
        numStr.push_back(to_string(n));
    }

    sort(numStr.begin(), numStr.end(), [](const string& a, const string& b) {
        return a + b > b + a; // Compare concatenated results to get the largest number
    });
    if ( numStr[0] == "0" ) {
        return "0";
    }

    string ans;
    for ( string s : numStr ) {
        ans += s;
    }

    return ans;
}