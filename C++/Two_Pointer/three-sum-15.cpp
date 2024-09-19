// Two Pointer with Set Tracker - [Leetcode 15](https://leetcode.com/problems/3sum/)

using namespace std;

#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> res;
    unordered_set<int> duplicates;
    unordered_map<int, int> seen;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // Means that you can insert into the set
        if (duplicates.insert(nums[i]).second)
        {
            for (int j = i + 1; j < n; j++)
            {
                // Find the complement of the two values
                int complement = -nums[i] - nums[j];
                if (seen.find(complement) != seen.end())
                {
                    if (seen[complement] == i)
                    {
                        vector<int> trip = {nums[i], nums[j], complement};
                        sort(trip.begin(), trip.end());
                        res.insert(trip);
                    }
                }
                // Means you can use the J value in the same outer loop ..
                seen[nums[j]] = i;
            }
        }
    }
    return vector<vector<int>>(res.begin(), res.end());
}