// Sorting and Converting String - [Leetcode 539](https://leetcode.com/problems/minimum-time-difference/description/)

#include <vector>

using namespace std;

int findMinDifference(vector<string>& timePoints) {
    // Convert into minutes (One Unit)
    vector<int> minutes;
    for ( auto t: timePoints ) {
        int hours = stoi(t.substr(0,2));
        int min = stoi(t.substr(3));
        minutes.push_back(hours * 60 + min);
    }

    // Sort on that Vector<int>
    sort( minutes.begin(), minutes.end() );

    int ans = INT_MAX;
    // Find minimum difference
    for ( int i = 1 ; i < minutes.size(); i++ ) {
        ans = min(ans, minutes[i] - minutes[i-1] );
    }
    
    // wrap around 23:59 to 00:00 is 1 
    int wrapAroundDiff = 24 * 60 - minutes.back() + minutes[0];
    return min(ans, wrapAroundDiff);

}