def checkMagic(grid: List[List[int]], i: int, j: int) -> bool:
    arr = [False for _ in range(9)]
    checkSum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2]
    for row in range(i, i + 3):
        for col in range(j, j + 3):
            if grid[row][col] == 0 or grid[row][col] > 9 or arr[grid[row][col] - 1]:
                return False
            arr[grid[row][col] - 1] = True
    row2 =  grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2]
    row3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2]
    if row2 != checkSum or row3 != checkSum:
        return False
    col1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j]
    col2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1]
    col3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2]
    if col1 != checkSum or col2 != checkSum or col3 != checkSum:
        return False
    diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2]
    diag2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j]
    if diag1 != checkSum or diag2 != checkSum:
        return False
    return True
class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        res = 0
        for i in range(len(grid) - 2):
            for j in range(len(grid[0]) - 2):
                if checkMagic(grid, i, j):
                    res += 1
        return res