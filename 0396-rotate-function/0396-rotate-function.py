class Solution:
    def maxRotateFunction(self, nums: List[int]) -> int:
        n = len(nums)
        last = 0
        tot = 0
        for i in range(n):
            last += (i * nums[i])
            tot += nums[i]
        res = last
        for i in range(n - 1):
            last = last + tot - n * nums[n - i - 1]
            res = max(res, last)
        return res