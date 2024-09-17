// Two Pointer with Basic Tracker - [Leetcode 392](https://leetcode.com/problems/is-subsequence/description/)

#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
  // Loop through T and have an index tracker
  // If t[i] == s[tracker] then tracker += 1
  // Return if tracker >= s.size()
  int tracker = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == s[tracker]) {
      tracker += 1;
    }
    if (tracker >= s.size()) {
      return true;
    }
  }
  return tracker >= s.size();
}