class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        res = float('inf')
        n = len(nums)
        preSum = 0
        sufSum = 0
        pre = {}
        suf = {}
        for i in range(n):
            preSum += nums[i]
            sufSum += nums[n - i - 1]
            pre[preSum] = i
            suf[sufSum] = n - i - 1
            if preSum == x or sufSum == x:
                res = min(res, i + 1)
            if (x - preSum) in suf and i < suf[x - preSum]:
                res = min(res, i + 1 + n - suf[x - preSum])
            if (x - sufSum) in pre and n - i - 1 > pre[x - sufSum]:
                res = min(res, i + 2 + pre[x - sufSum])
        return -1 if res == float('inf') else res