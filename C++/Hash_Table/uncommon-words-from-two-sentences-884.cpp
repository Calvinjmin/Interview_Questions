// Using String Stream to Split w/ Hash Table - [Leetcode 884](https://leetcode.com/problems/uncommon-words-from-two-sentences/description/)

#include <ratio>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> uncommonFromSentences(string s1, string s2) {
  unordered_map<string, int> wordCount;
  vector<string> result;

  auto processSentence = [&](const string &s) {
    stringstream ss(s);
    string word;
    while (ss >> word) {
      ++wordCount[word];
    }
  };

  processSentence(s1);
  processSentence(s2);

  for (auto pair : wordCount) {
    if (pair.second == 1) {
      result.push_back(pair.first);
    }
  }

  return result;
}