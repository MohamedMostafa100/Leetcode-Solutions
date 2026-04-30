class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[[None for _ in range(k + 1)] for _ in range(n)] for _ in range(m)]
        def solve(i: int, j: int, cost: int) -> int:
            if i == m or j == n:
                return float('-inf')
            cost += (1 if grid[i][j] > 0 else 0)
            if cost > k:
                return float('-inf')
            if i == m - 1 and j == n - 1:
                return grid[i][j]
            if dp[i][j][cost] == None:
                dp[i][j][cost] = float('-inf')
                dp[i][j][cost] = max(dp[i][j][cost], solve(i + 1, j, cost) + grid[i][j])
                dp[i][j][cost] = max(dp[i][j][cost], solve(i, j + 1, cost) + grid[i][j])
            return dp[i][j][cost]
        res = solve(0, 0, 0)
        return res if res >= 0 else -1