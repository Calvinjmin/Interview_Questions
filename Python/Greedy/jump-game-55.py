# Max Jump as Greedy Choice - [Leetcode 55](https://leetcode.com/problems/jump-game/)
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxJump = 0
        for idx, val in enumerate(nums):
            if maxJump < idx:
                return False
            maxJump = max(maxJump, idx + val)
        return True
