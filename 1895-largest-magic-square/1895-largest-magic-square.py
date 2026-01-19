class Solution:
    def largestMagicSquare(self, grid: list[list[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        rowSum = [[0] * m for _ in range(n)]
        colSum = [[0] * n for _ in range(m)]
        for i in range(n):
            current_sum = 0
            for j in range(m):
                current_sum += grid[i][j]
                rowSum[i][j] = current_sum    
        for j in range(m):
            current_sum = 0
            for i in range(n):
                current_sum += grid[i][j]
                colSum[j][i] = current_sum
        def checkSquare(row, col, side):
            compSum = rowSum[row][col + side - 1] - rowSum[row][col] + grid[row][col]
            for i in range(row + 1, row + side):
                current_row_sum = rowSum[i][col + side - 1] - rowSum[i][col] + grid[i][col]
                if current_row_sum != compSum:
                    return False
            for j in range(col, col + side):
                current_col_sum = colSum[j][row + side - 1] - colSum[j][row] + grid[row][j]
                if current_col_sum != compSum:
                    return False
            sumDiag1 = 0
            for k in range(side):
                sumDiag1 += grid[row + k][col + k]
            if sumDiag1 != compSum:
                return False
            sumDiag2 = 0
            for k in range(side):
                sumDiag2 += grid[row + k][col + side - 1 - k]
            if sumDiag2 != compSum:
                return False     
            return True
        res = 1
        maxSide = min(n, m)
        for side in range(2, maxSide + 1):
            flag = False
            for i in range(n - side + 1):
                for j in range(m - side + 1):
                    if checkSquare(i, j, side):
                        res = side
                        flag = True
                        break
                if flag:
                    break         
        return res