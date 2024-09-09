// Basics of Binary Search - [Leetcode 35](https://leetcode.com/problems/search-insert-position/description)

#include <vector>

using namespace std;

// REMEMBER - To calculate the middle position, it is low + (high - low) / 2
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n -1;
    int mid = 0;

    while ( left <= right ) {
        mid = left + (right-left) / 2;
        if ( nums[mid] == target ) {
            return mid;
        }
        if ( nums[mid] > target ) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

    }
    return left;
}