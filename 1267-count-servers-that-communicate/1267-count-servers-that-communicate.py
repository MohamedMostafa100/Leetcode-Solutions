class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        res = 0
        m = len(grid)
        n = len(grid[0])
        rows = [0 for _ in range(m)]
        cols = [0 for _ in range(n)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    rows[i] += 1
                    cols[j] += 1
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (rows[i] > 1 or cols[j] > 1):
                    res += 1
        return res
                    