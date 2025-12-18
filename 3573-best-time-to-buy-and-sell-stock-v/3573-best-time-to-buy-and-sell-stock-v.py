def solve(prices: List[int], dp: List[List[List[int]]], i: int, k: int, s: int) -> int:
    if i == len(prices):
        return 0 if s == 0 else float('-inf') / 2
    if dp[i][k][s] == -1:
        dp[i][k][s] = float('-inf')
        dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k, s))
        if k > 0:
            if s == 0:
                dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k, 1) - prices[i])
                dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k, 2) + prices[i])
            elif s == 1:
                dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k - 1, 0) + prices[i])
            else:
                dp[i][k][s] = max(dp[i][k][s], solve(prices, dp, i + 1, k - 1, 0) - prices[i])
    return dp[i][k][s]
class Solution:
    
    def maximumProfit(self, prices: List[int], k: int) -> int:
        dp = [[[-1 for _ in range(3)] for _ in range(k + 1)] for _ in range(len(prices))]
        return solve(prices, dp, 0, k, 0)