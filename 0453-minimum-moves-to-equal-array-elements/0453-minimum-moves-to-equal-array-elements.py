class Solution:
    def minMoves(self, nums: list[int]) -> int:
        res = 0
        mn = min(nums)
        for num in nums:
            res += num - mn
        return res