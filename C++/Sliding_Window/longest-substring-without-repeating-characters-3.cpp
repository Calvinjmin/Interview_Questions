// Set with Sliding Window - [Leetcode 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
  set<char> charSet;
  int ans = 0;
  int left = 0;
  int right = 0;

  while (right < s.length()) {
    char curr = s[right];
    while (charSet.find(curr) != charSet.end()) {
      charSet.erase(s[left]);
      left += 1;
    }
    charSet.insert(s[right]);
    ans = max(ans, right - left + 1);
    right += 1;
  }

  return ans;
}