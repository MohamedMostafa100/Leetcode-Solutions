class Solution:
    def rearrangeSticks(self, n: int, k: int) -> int:
        dp = [[-1 for _ in range(k + 1)] for _ in range(n + 1)]
        def solve(n: int, k: int) -> int:
            if n < k or k == 0:
                return 0
            if n == k:
                return 1
            if dp[n][k] == -1:
                dp[n][k] = 0
                dp[n][k] = (dp[n][k] + solve(n - 1, k - 1)) % 1000000007
                dp[n][k] = (dp[n][k] + ((solve(n - 1, k) * (n - 1)) % 1000000007)) % 1000000007
            return dp[n][k] % 1000000007
        return solve(n, k)
