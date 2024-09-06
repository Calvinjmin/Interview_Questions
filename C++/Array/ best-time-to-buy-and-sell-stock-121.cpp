/* 
    LeetCode Question 121
    Best Time to Buy and Sell Stock
*/

#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = prices[0];
    int profit = 0;

    for ( int i = 1; i < prices.size(); i++ ) {
        minPrice = min( prices[i], minPrice );
        profit = max( profit, prices[i] - minPrice );
    }
    return profit;
}