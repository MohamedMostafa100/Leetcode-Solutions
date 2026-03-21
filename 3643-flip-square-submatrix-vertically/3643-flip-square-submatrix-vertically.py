class Solution:
    def reverseSubmatrix(self, grid: List[List[int]], x: int, y: int, k: int) -> List[List[int]]:
        for i in range(x, (2 * x + k) // 2):
            for j in range(y, y + k):
                grid[i][j], grid[(x + k - 1) - (i - x)][j] = grid[(x + k - 1) - (i - x)][j], grid[i][j]
        return grid