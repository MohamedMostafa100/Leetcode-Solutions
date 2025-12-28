class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        res = 0
        i = len(grid) - 1
        j = 0
        while i >= 0 and j < len(grid[0]):
            while j < len(grid[0]) and grid[i][j] >= 0:
                j += 1
            res += len(grid[0]) - j
            i -= 1
        return res
