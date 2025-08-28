class Solution:
    def diagSort(self, grid: List[List[int]], i: int, j: int, asc: bool):
        while i < len(grid) and j < len(grid):
            targetNum = grid[i][j]
            targetNumX = i
            targetNumY = j
            x = i + 1
            y = j + 1
            while x < len(grid) and y < len(grid):
                if asc:
                    if grid[x][y] < targetNum:
                        targetNum = grid[x][y]
                        targetNumX = x
                        targetNumY = y
                else:
                    if grid[x][y] > targetNum:
                        targetNum = grid[x][y]
                        targetNumX = x
                        targetNumY = y
                x += 1
                y += 1
            temp = grid[i][j]
            grid[i][j] = grid[targetNumX][targetNumY]
            grid[targetNumX][targetNumY] = temp
            i += 1
            j += 1
                        
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        for i in range(1, len(grid)):
            self.diagSort(grid, 0, i, True)
        for i in range(0, len(grid)):
            self.diagSort(grid, i, 0, False)
        return grid
        