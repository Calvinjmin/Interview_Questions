// Hash Table to hold complement - [Leetcode 1](https://leetcode.com/problems/two-sum/)

using namespace std;

#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> comp_ind;

    for ( int i = 0; i < nums.size(); i++ ) {
        int comp = target - nums[i];
        if ( comp_ind.find(comp) != comp_ind.end() ) {
            vector<int> res = {i, comp_ind[comp]};
            return res;
        }
        comp_ind[nums[i]] = i;
    }
    return {};
}