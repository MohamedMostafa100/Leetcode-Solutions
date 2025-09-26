class Solution:
    def solve(self, triangle: List[List[int]], dp: List[int], i: int, j: int) -> int:
        if i == len(triangle):
            return 0
        idx = (i * (i + 1) // 2) + j
        if dp[idx] == None:
            dp[idx] = triangle[i][j] + min(self.solve(triangle, dp, i + 1, j), self.solve(triangle, dp, i + 1, j + 1))
        return dp[idx]
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle) * (len(triangle) + 1) // 2
        dp = [None for i in range(n)]
        return self.solve(triangle, dp, 0, 0)