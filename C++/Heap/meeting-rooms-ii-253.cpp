// Using Heap with Basic Logic - [Leetcode 253](https://leetcode.com/problems/meeting-rooms-ii/description)

using namespace std;

#include<vector>
#include<priority_queue>

int minMeetingRooms(vector<vector<int>>& intervals) {
    // use a heap to see the max number of rooms
    if ( intervals.size() == 0 ) return 0;

    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });
    int ans = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(intervals[0][1]);
    for ( int i = 1; i < intervals.size(); i++ ) {
        // if the current time is less than heap
        if ( pq.top() <= intervals[i][0] ) {
            pq.pop();
        }
        pq.push( intervals[i][1] );
        ans = max( ans, (int)pq.size() );
    }
    return ans;
}
