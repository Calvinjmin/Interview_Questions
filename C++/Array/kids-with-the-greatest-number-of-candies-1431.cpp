// Array Manipulation with Max Value - [Leetcode
// 1431](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/)

#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
  vector<bool> ans(candies.size(), false);
  int maxCandy = -1;
  for (int c : candies) {
    maxCandy = max(c, maxCandy);
  }

  for (int i = 0; i < candies.size(); i++) {
    int curr = candies[i];
    ans[i] = (candies[i] + extraCandies) >= maxCandy;
  }

  return ans;
}