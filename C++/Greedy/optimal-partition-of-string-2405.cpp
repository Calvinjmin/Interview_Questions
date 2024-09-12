// Take longest substring until there is a duplicate - [Leetcode 2405](https://leetcode.com/problems/optimal-partition-of-string/description/)

using namespace std;

#include <string>
#include <unordered_set>

int partitionString(string s) {
    unordered_set<char> seen;
    int answer = 1;

    for ( char c : s ) {
        if ( seen.find(c) != seen.end() ) {
            seen = {c};
            answer += 1;
        }
        else {
            seen.insert(c);
        }
    }

    return answer;
}