class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        res = 0
        dp = [[0 for j in range(k)] for i in range(k)]
        for num in nums:
            mod = num % k
            for rem in range(k):
                diff = rem - mod + k % k
                dp[mod][rem] = dp[diff][rem] + 1
                res = max(res, dp[mod][rem])
        return res