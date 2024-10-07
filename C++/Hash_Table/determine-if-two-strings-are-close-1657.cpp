// Set with Freq Map Equality - [Leetcode 1657](https://leetcode.com/problems/determine-if-two-strings-are-close)

#include<vector>
#include<set>

bool closeStrings(string word1, string word2) {
    vector<int> countA(26, 0);
    vector<int> countB(26, 0);
    set<char> uniA;
    set<char> uniB;

    for ( auto c: word1 ) {
        countA[tolower(c) - 'a']++;
        uniA.insert(c);
    }
    for ( auto c: word2 ) {
        countB[tolower(c) - 'a']++;
        uniB.insert(c);
    }
    if ( uniA != uniB ) {
        return false;
    }
    sort(countA.begin(), countA.end());
    sort(countB.begin(), countB.end());

    return countA == countB;
}
