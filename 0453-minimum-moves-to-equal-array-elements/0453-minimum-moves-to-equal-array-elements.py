class Solution:
    def minMoves(self, nums: list[int]) -> int:
        res = 0
        nums.sort()
        for num in nums[1:]:
            res += num - nums[0]
        return res