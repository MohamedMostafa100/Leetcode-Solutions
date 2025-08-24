class Solution:
    def minimumArea(self, grid: List[List[int]], rowStart: int, rowEnd: int, colStart: int, colEnd: int) -> int:
        topLeft = None
        bottomRight = None
        for i in range(rowStart, rowEnd + 1):
            for j in range(colStart, colEnd + 1):
                if grid[i][j] == 1:
                    if not topLeft:
                        topLeft = (i, j)
                        bottomRight = (i, j)
                    else:
                        topLeft = (topLeft[0], min(topLeft[1], j))
                        bottomRight = (i, max(bottomRight[1], j))
        if topLeft == None:
            return float('inf') / 3
        return (bottomRight[0] - topLeft[0] + 1) * (bottomRight[1] - topLeft[1] + 1)
    def solve(self, grid: List[List[int]]) -> int:
        res = float('inf')
        #3 Vertical Splits
        for i in range(0, len(grid[0]) - 2):
            for j in range(i + 1, len(grid[0]) - 1):
                split1 = self.minimumArea(grid, 0, len(grid) - 1, 0, i)
                split2 = self.minimumArea(grid, 0, len(grid) - 1, i + 1, j)
                split3 = self.minimumArea(grid, 0, len(grid) - 1, j + 1, len(grid[0]) - 1)
                res = min(res, split1 + split2 + split3)
        #1 Vertical and 2 Horizontal Splits
        for i in range(0, len(grid) - 1):
            for j in range(0, len(grid[0]) - 1):
                split1 = self.minimumArea(grid, 0, len(grid) - 1, 0, j)
                split2 = self.minimumArea(grid, 0, i, j + 1, len(grid[0]) - 1)
                split3 = self.minimumArea(grid, i + 1, len(grid) - 1, j + 1, len(grid[0]) - 1)
                res = min(res, split1 + split2 + split3)
                split1 = self.minimumArea(grid, 0, i, 0, j)
                split2 = self.minimumArea(grid, i + 1, len(grid) - 1, 0, j)
                split3 = self.minimumArea(grid, 0, len(grid) - 1, j + 1, len(grid[0]) - 1)
                res = min(res, split1 + split2 + split3)
        return res
    def minimumSum(self, grid: List[List[int]]) -> int:
        gridTransposed = []
        for i in range(len(grid[0])):
            newRow = []
            for j in range(len(grid)):
                newRow.append(grid[j][i])
            gridTransposed.append(newRow)
        return min(self.solve(grid), self.solve(gridTransposed))

        