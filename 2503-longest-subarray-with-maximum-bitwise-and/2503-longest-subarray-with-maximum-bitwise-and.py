class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        res = 0
        maxAnd = 0
        andSum = ~0
        l = 0
        for r in range(len(nums)):
            if (andSum & nums[r]) < andSum or andSum < nums[r]:
                l = r
                andSum = ~0
            andSum &= nums[r]
            if andSum > maxAnd:
                maxAnd = andSum
                res = r - l + 1
            elif andSum == maxAnd:
                res = max(res, r - l + 1)
        return res

        