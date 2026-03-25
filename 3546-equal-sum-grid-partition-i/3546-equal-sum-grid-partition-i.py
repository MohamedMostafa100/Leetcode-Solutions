class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        tot = 0
        rowSums = [0 for _ in range(len(grid))]
        colSums = [0 for _ in range(len(grid[0]))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                tot += grid[i][j]
                rowSums[i] += grid[i][j]
                colSums[j] += grid[i][j]
        i = 0
        j = 0
        preRow = 0
        preCol = 0
        while i < len(rowSums) or j < len(colSums):
            if i < len(rowSums):
                preRow += rowSums[i]
                if preRow == (tot - preRow):
                    return True
                i += 1
            if j < len(colSums):
                preCol += colSums[j]
                if preCol == (tot - preCol):
                    return True
                j += 1
        return False