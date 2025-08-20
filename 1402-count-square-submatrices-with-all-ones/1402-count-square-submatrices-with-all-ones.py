class Solution:
    def solve(self, matrix: List[List[int]], dp: List[List[int]], i: int, j: int) -> int:
        if i == len(matrix) or j == len(matrix[0]) or matrix[i][j] == 0:
            return 0
        if dp[i][j] == -1:
            right = self.solve(matrix, dp, i, j + 1)
            down = self.solve(matrix, dp, i + 1, j)
            diag = self.solve(matrix, dp, i + 1, j + 1)
            dp[i][j] = 1 + min(right, down, diag)
        return dp[i][j]
    def countSquares(self, matrix: List[List[int]]) -> int:
        res = 0
        dp = [[-1 for cell in row] for row in matrix]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res += self.solve(matrix, dp, i, j)
        return res
        