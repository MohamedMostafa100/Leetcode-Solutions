class Solution:
    def uniquePaths(self, grid: List[List[int]]) -> int:
        mod = 1000000007
        m = len(grid)
        n = len(grid[0])
        dp = [[[-1 for _ in range(3)] for _ in range(n)] for _ in range(m)]
        def solve(i: int, j: int, dir: int) -> int:
            if i < 0 or j < 0 or i >= m or j >= n:
                return 0
            if i == m - 1 and j == n - 1:
                return 1
            if dp[i][j][dir] == -1:
                dp[i][j][dir] = 0
                if grid[i][j] == 1:
                    if dir == 1:
                        dp[i][j][dir] = (dp[i][j][dir] + solve(i + 1, j, 2)) % mod
                    else:
                        dp[i][j][dir] = (dp[i][j][dir] + solve(i, j + 1, 1)) % mod
                else:
                    dp[i][j][dir] = (dp[i][j][dir] + solve(i + 1, j, 2)) % mod
                    dp[i][j][dir] = (dp[i][j][dir] + solve(i, j + 1, 1)) % mod
            return dp[i][j][dir] % mod
        return solve(0, 0, 0)