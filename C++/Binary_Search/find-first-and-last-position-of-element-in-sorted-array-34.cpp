// Modified Binary Search to look left and right - [Leetcode 34](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};

    auto binarySearch = [&](bool findFirst) {
        int low = 0, high = nums.size() - 1, result = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                result = mid;
                if (findFirst) {
                    // think of the case [ 1,1,1,1,1,1,1 ] - you need to find the first instance of 1
                    high = mid - 1;
                } else {
                    // same as here -> keep looking right
                    low = mid + 1;
                }
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    };

    int firstPos = binarySearch(true);
    if (firstPos == -1) return {-1, -1};
    int lastPos = binarySearch(false);

    return {firstPos, lastPos};
}