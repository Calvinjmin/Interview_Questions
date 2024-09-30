// Lower Bound Set Method - [Leetcode 729](https://leetcode.com/problems/my-calendar-i/description/)

using namespace std;

#include<set>

class MyCalendar {
private:
    set<pair<int,int>> calendar;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        const pair<int,int> event = {start,end};
    
        // Exists Already 
        const auto nextEvent = calendar.lower_bound(event);
        if ( nextEvent != calendar.end() && nextEvent -> first < end ) {
            return false;
        }

        // Overlapping Interval
        if ( nextEvent != calendar.begin() ) {
            const auto prevEvent = prev(nextEvent);
            if ( prevEvent -> second > start ) {
                return false;
            }
        }

        calendar.insert(event);
        return true;
    }
};

