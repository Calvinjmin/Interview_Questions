// Basics of a Prefix Tree - [Leetcode 386](https://leetcode.com/problems/lexicographical-numbers)

using namespace std;

#include <vector>

class Solution {
private:
    vector<int> ans;
public:
    vector<int> lexicalOrder(int n) {
        for ( int i = 1; i < 10; i++ ) {
            dfs( i, n );
        }
        return ans;
    }
    void dfs( int curr, int limit ) {
        if ( curr > limit ) {
            return;
        }
        ans.push_back(curr);
        for ( int i = 0; i < 10; i++ ) {
            int newNum = curr * 10 + i;
            if ( newNum <= limit ) {
                dfs( newNum , limit );
            }
        }
    }
};