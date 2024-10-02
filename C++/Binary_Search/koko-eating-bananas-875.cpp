// Binary Search to Find Rate - [Leetcode 875](https://leetcode.com/problems/koko-eating-bananas/)

using namespace std;

#include<vector>

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end()); 

    while (left<right) {
        int middle = (left + right ) / 2;
        int hourSpent = 0;

        for ( int p: piles ) {
            // Time it takes to eat pile + 1 if there is a leftover
            hourSpent += p / middle + ( p % middle != 0 );
        }

        if ( hourSpent <= h ) {
            right = middle;
        }
        else {
            left = middle + 1;
        }
    }

    return right;

}
