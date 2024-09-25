// Maximize Profits with Priority Queue - [Leetcode 502](https://leetcode.com/problems/ipo/description/)

using namespace std;

#include<vector>

// w is inital capital
// k is the most number of projects you can do
// maximize profits with capital
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    // maximize profits with given capital
    int n = profits.size();

    vector<pair<int,int>> projects;
    for ( int i = 0; i < n; i++ ) {
        projects.emplace_back(capital[i], profits[i]);
    }
    sort( projects.begin(), projects.end() );

    priority_queue<int> q;
    int ptr = 0;
    for ( int i = 0; i < k; i++ ) {
        // find all suitable projects and pop the most profitable
        while ( ptr < n && projects[ptr].first <= w ) {
            q.push( projects[ptr].second );
            ptr += 1;
        }
        if ( q.empty() ) {
            break;
        }
        w += q.top();
        q.pop();
    }
    return w;
}
