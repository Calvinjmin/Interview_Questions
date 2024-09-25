// Math Logic with Array Trackers - [Leetcode 134](https://leetcode.com/problems/gas-station/description/)

using namespace std;

#include <vector>

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // Curr Gain is Current Trip -> Segementing
    // Total Gain is Net Gain
    int currGain = 0, totalGain = 0, answer = 0;

    for (int i = 0; i < gas.size(); ++i) {
        totalGain += gas[i] - cost[i];
        currGain += gas[i] - cost[i];

        // Answer is the starting location
        if (currGain < 0) {
            answer = i + 1;
            currGain = 0;
        }
    }

    return totalGain >= 0 ? answer : -1;
}