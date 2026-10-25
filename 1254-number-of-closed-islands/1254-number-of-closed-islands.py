class Solution:
    def closedIsland(self, grid: list[list[int]]) -> int:
        res = 0
        m = len(grid)
        n = len(grid[0])
        visited = [[-1 for _ in range(n)] for _ in range(m)]
        def dfs(i: int, j: int) -> int:
            if grid[i][j] == 1:
                return 1
            if i == 0 or j == 0 or i == m - 1 or j == n - 1:
                visited[i][j] = 0
            if visited[i][j] == -1:
                visited[i][j] = 2
                visited[i][j] = min(dfs(i + 1, j), dfs(i, j + 1), dfs(i - 1, j), dfs(i, j - 1))
            return visited[i][j]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0 and visited[i][j] == -1 and dfs(i, j) == 1:
                    res += 1
        return res