class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        dp = [[-1 for _ in range(2 * len(piles) + 1)] for _ in range(len(piles))]
        tot = sum(piles)
        def solve(rem: int, i: int, m: int) -> int:
            if i + 2 * m >= len(piles):
                return rem
            if dp[i][m] == -1:
                res = float('inf')
                curRem = rem
                for x in range(1, 2 * m + 1):
                    curRem -= piles[i + x - 1]
                    res = min(res, solve(curRem, i + x, max(m, x)))
                dp[i][m] = rem - res
            return dp[i][m]
        return solve(tot, 0, 1)