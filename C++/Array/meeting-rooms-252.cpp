// Basic 2D Vector Sorting - [Leetcode 252](https://leetcode.com/problems/meeting-rooms/description/)

#include<vector>

bool canAttendMeetings(vector<vector<int>>& intervals) {
    if ( intervals.size() == 0 ) return true;

    // Sort meeting rooms based on start time
    sort( intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        return a[0] < b[0];
    });

    int end = intervals[0][1];
    for ( int i = 1; i < intervals.size(); i++ ) {
        if ( end > intervals[i][0]) {
            return false;
        }
        end = intervals[i][1];
    }
    return true;
}
