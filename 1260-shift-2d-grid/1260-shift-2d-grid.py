class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                curPos = i * n + j
                newPos = (curPos + k) % (m * n)
                res[newPos // n][newPos % n] = grid[i][j]
        return res