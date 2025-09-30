class Solution:
    def solve(self, values: List[int], dp: List[List[int]], i: int, j: int) -> int:
        if j - i < 2:
            return 0
        elif j - i == 2:
            return values[i] * values[i + 1] * values[j]
        if dp[i][j] == -1:
            dp[i][j] = float('inf')
            for k in range(i + 1, j):
                sub = values[i] * values[k] * values[j] + self.solve(values, dp, i, k) + self.solve(values, dp, k, j)
                dp[i][j] = min(dp[i][j], sub)
        return dp[i][j]
    def minScoreTriangulation(self, values: List[int]) -> int:
        dp = [[-1 for j in range(len(values))] for i in range(len(values))]
        return self.solve(values, dp, 0, len(values) - 1)
        