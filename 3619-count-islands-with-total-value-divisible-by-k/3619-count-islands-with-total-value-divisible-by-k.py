class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        res = 0
        m = len(grid)
        n = len(grid[0])
        vis = [[False for _ in range(n)] for _ in range(m)]
        def dfs(i: int, j: int) -> int:
            if i < 0 or j < 0 or i == m or j == n or vis[i][j] or grid[i][j] == 0:
                return 0
            vis[i][j] = True
            return (grid[i][j] + dfs(i + 1, j) + dfs(i, j + 1) + dfs(i - 1, j) + dfs(i, j - 1)) % k
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0 and not vis[i][j] and dfs(i, j) == 0:
                    res += 1
        return res