class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        res = 0
        dp = [0 for i in range(n + 1)]
        if k == 0 or k - 1 + maxPts <= n:
            return 1
        dp[0] = 1
        winSum = dp[0]
        for i in range(1, n + 1):
            dp[i] = winSum / maxPts
            if i < k:
                winSum += dp[i]
            else:
                res += dp[i]
            if i >= maxPts:
                winSum -= dp[i - maxPts]
        return res
        