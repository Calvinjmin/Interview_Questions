// Key Generation using Freq Map - [Leetcode 49](https://leetcode.com/problems/group-anagrams)

using namespace std;

#include <vector>
#include <unordered_map>

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Anagram - Same # of letters in a word
    unordered_map<string, vector<string>> count;
    for ( string word: strs ) {
        string key = word;
        sort(key.begin(), key.end());
        count[key].push_back(word);
    }

    vector<vector<string>> ans;
    for ( auto p : count ) {
        ans.push_back(p.second);
    }
    return ans;
}
