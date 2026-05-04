class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        start = 0
        end = n - 1
        for i in range(n // 2):
            for j in range(start, end):
                matrix[i][j], matrix[j][end] = matrix[j][end], matrix[i][j]
                matrix[i][j], matrix[end][end - j + start] = matrix[end][end - j + start], matrix[i][j]
                matrix[i][j], matrix[end - j + start][i] = matrix[end - j + start][i], matrix[i][j]
            start += 1
            end -= 1
        