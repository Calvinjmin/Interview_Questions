// Elevated TwoSum - [Leetcode 128](https://leetcode.com/problems/longest-consecutive-sequence/)

#include <unordered_set>
#include <vector>

using namespace std;


/*
    An alternative to the contains() function ...
    !hash_set.find( curr - 1 ) != hash_set.end()
*/

int longestConsecutive(vector<int> &nums) {
  if (nums.size() == 0) {
    return 0;
  }
  int streak = 1;
  unordered_set<int> hash_set(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    int curr = nums[i];
    if (!hash_set.contains(curr - 1)) {
      int j = 1;
      while (hash_set.contains(curr + j)) {
        j += 1;
      }
      streak = max(streak, j);
    }
  }

  return streak;
}