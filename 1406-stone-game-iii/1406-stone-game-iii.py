class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [None for _ in range(n)]
        def solve(i: int) -> int:
            if i == n:
                return 0
            if dp[i] == None:
                dp[i] = float('-inf')
                dp[i] = max(dp[i], stoneValue[i] - solve(i + 1))
                if i + 1 < n:
                    dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] - solve(i + 2))
                if i + 2 < n:
                    dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(i + 3))
            return dp[i]
        res = solve(0)
        if res > 0:
            return "Alice"
        elif res < 0:
            return "Bob"
        return "Tie"
