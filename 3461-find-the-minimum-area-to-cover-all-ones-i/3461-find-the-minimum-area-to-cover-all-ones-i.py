class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        topLeft = None
        bottomRight = None
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    if not topLeft:
                        topLeft = (i, j)
                        bottomRight = (i, j)
                    else:
                        topLeft = (topLeft[0], min(topLeft[1], j))
                        bottomRight = (i, max(bottomRight[1], j))
        return (bottomRight[0] - topLeft[0] + 1) * (bottomRight[1] - topLeft[1] + 1)
