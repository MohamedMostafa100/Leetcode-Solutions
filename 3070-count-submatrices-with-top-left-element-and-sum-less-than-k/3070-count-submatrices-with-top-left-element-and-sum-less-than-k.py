class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        res = 0
        for j in range(len(grid[0])):
            tot = 0
            if j > 0 and (grid[0][j - 1] + grid[0][j] > k):
                break
            for i in range(len(grid)):
                if j > 0:
                    grid[i][j] += grid[i][j - 1]
                tot += grid[i][j]
                if tot > k:
                    break
                res += 1
        return res