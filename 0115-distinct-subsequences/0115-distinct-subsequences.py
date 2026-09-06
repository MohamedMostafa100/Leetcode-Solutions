class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        dp = [[-1 for _ in range(len(t))] for _ in range(len(s))]
        def solve(i: int, j: int) -> int:
            if j == len(t):
                return 1
            if i == len(s):
                return 0
            if dp[i][j] == -1:
                dp[i][j] = 0
                if s[i] == t[j]:
                    dp[i][j] += solve(i + 1, j + 1)
                dp[i][j] += solve(i + 1, j)
            return dp[i][j]
        return solve(0, 0)