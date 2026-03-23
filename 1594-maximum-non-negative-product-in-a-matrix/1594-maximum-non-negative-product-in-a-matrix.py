MOD = 1000000007
class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[(float('-inf'), float('inf')) for _ in range(n)] for _ in range(m)]
        dp[m - 1][n - 1] = (grid[m - 1][n - 1], grid[m - 1][n - 1])
        def solve(i: int, j: int) -> tuple[int, int]:
            if i == m or j == n:
                return (float('-inf'), float('inf'))
            if dp[i][j] == (float('-inf'), float('inf')):
                r = solve(i, j + 1)
                if r != (float('-inf'), float('inf')):
                    dp[i][j] = (max(dp[i][j][0], grid[i][j] * r[0], grid[i][j] * r[1]), min(dp[i][j][1], grid[i][j] * r[0], grid[i][j] * r[1]))
                d = solve(i + 1, j)
                if d != (float('-inf'), float('inf')):
                    dp[i][j] = (max(dp[i][j][0], grid[i][j] * d[0], grid[i][j] * d[1]), min(dp[i][j][1], grid[i][j] * d[0], grid[i][j] * d[1]))
            return dp[i][j]
        res = solve(0, 0)[0]
        return res % MOD if res > -1 else -1