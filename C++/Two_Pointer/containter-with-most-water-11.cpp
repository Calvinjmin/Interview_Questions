// Out to In Two Pointer - [Leetcode 11](https://leetcode.com/problems/container-with-most-water/description/)

#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int maxA = 0;
    int left = 0;
    int right = height.size() - 1;

    int curr = 0;
    while (left < right ) {
        curr = min ( height[right], height[left] ) * (right - left);

        maxA = max( maxA, curr );
        if ( height[left] < height[right] ) {
            left += 1;
        }
        else {
            right -= 1;
        }

    }
    return maxA;
    
}