// Prefix Window - [Leetcode 438](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)

#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
  vector<int> ans;
  if (p.length() > s.length()) {
    return ans;
  }

  vector<int> pfreq(26, 0);
  for (char c : p) {
    pfreq[c - 'a'] += 1;
  }

  int left = 0;
  int right = p.length() - 1;

  vector<int> sfreq(26, 0);
  for (char x : s.substr(0, right + 1)) {
    sfreq[x - 'a'] += 1;
  }

  while (right < s.length()) {
    if (pfreq == sfreq) {
      ans.push_back(left);
    }

    // Slide the window
    sfreq[s[left] - 'a'] -= 1;
    left += 1;
    right += 1;

    // Check bounds before updating sfreq
    if (right < s.length()) {
      sfreq[s[right] - 'a'] += 1;
    }
  }
  return ans;
}