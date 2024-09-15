// Frequency Map w/ Basic Sorting - [Leetcode 2268](https://leetcode.com/problems/minimum-number-of-keypresses/description/)

#include <vector>

using namespace std;

int minimumKeypresses(string s) {
  vector<int> freq(26, 0);
  for (char c : s) {
    ++freq[c - 'a'];
  }

  sort(freq.begin(), freq.end(), greater<int>());

  int ans = 0;

  for (int i = 0; i < 26; i++) {
    int numPresses = 1;
    if (i > 8 and i <= 17) {
      numPresses = 2;
    } else if (i > 17) {
      numPresses = 3;
    }
    ans += numPresses * freq[i];
  }

  return ans;
}