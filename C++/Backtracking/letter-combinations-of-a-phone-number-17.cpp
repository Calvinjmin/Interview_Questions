// Iteration with Backtracking - [Leetcode 17](https://leetcode.com/problems/letter-combinations-of-a-phone-number/description)

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> combinations;
  unordered_map<char, string> combo = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

public:
  void backtrack(int index, string path, string digits) {
    if (path.length() == digits.length()) {
      combinations.push_back(path);
      return;
    }

    string poss = combo[digits[index]];
    for (char l : poss) {
      path.push_back(l);
      backtrack(index + 1, path, digits);
      path.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) {
      return combinations;
    }
    backtrack(0, "", digits);
    return combinations;
  }
};