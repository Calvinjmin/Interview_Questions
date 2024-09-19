// Permutations w/ all possible combinations - [Leetcode 47](https://leetcode.com/problems/permutations-ii/)

using namespace std;

#include <set>
#include <vector>

set<vector<int>> s;
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<int> vals;
    permutate( vals, nums, used );
    return vector<vector<int>>(s.begin(), s.end());

}
void permutate( vector<int>& vals, vector<int>& nums, vector<bool>& used ) {
    if ( vals.size() == nums.size() ) {
        s.insert(vals);
        return;
    }
    for ( int i = 0; i < nums.size(); i++ ) {
        if ( !used[i] ) {
            vals.push_back(nums[i]);
            used[i] = true;
            permutate( vals, nums, used );
            vals.pop_back();
            used[i] = false;
        }
    }
}