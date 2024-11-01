# Bottom Up DP - [Leetcode 198](https://leetcode.com/problems/house-robber/)

from typing import List

def rob(self, nums: List[int]) -> int:
    # 1 2 3 1
    # 1 2 4 4 
    if len(nums) < 2:
        return nums[0]
    dp = []
    dp.append( nums[0] )
    dp.append(max(nums[0], nums[1]))
    for i in range(2, len(nums)):
        dp.append(max( nums[i] + dp[i-2], dp[i-1]) )
    return dp[-1]
