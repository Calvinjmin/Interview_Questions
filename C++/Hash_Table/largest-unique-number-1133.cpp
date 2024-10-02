// Reverse Iterator with Map - [Leetcode 1133](https://leetcode.com/problems/largest-unique-number)

using namespace std;

#include<vector>
#include<map>

int largestUniqueNumber(vector<int>& nums) {   
    map<int,int> freq;
    for ( int a : nums ) {
        freq[a] += 1;
    }

    int ans = -1;
    // rBegin and rEnd are reverse Iterators
    for ( auto it = freq.rbegin(); it != freq.rend(); it++ ) {
        if ( it->second == 1 ) {
            return it->first;
        }
    }

    return ans;
    
}
