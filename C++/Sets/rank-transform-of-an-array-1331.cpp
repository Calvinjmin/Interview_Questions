// Auto Sort with Set - [Leetcode 1331](https://leetcode.com/problems/rank-transform-of-an-array/)

using namespace std;

#include<set>
#include<vector>
#include<unordered_map>

vector<int> arrayRankTransform(vector<int>& arr) {
    // create a hash map to store rank
    unordered_map<int,int> rank_map;
    // use a set to each all unique rank values
    set<int> s(arr.begin(), arr.end());
    int rank = 1;

    for ( int val: s ) {
        rank_map[val] = rank++;
    }

    vector<int> ans;
    for ( int i = 0; i < arr.size(); i++ ) {
        ans.push_back(rank_map[arr[i]]);
    }

    return ans;

}
