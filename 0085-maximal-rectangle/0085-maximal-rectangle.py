class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        res = 0
        right = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        down = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        up = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0]) - 1, -1, -1):
                if matrix[i][j] == '1':
                    if j == len(matrix[0]) - 1:
                        right[i][j] = 1
                    else:
                        right[i][j] = right[i][j + 1] + 1
        for j in range(len(matrix[0])):
            stk = []
            for i in range(len(matrix)):
                while len(stk) > 0 and right[i][j] <= right[stk[-1]][j]:
                    stk.pop()
                if len(stk) == 0:
                    up[i][j] = i + 1
                else:
                    up[i][j] = i - stk[-1]
                stk.append(i)
            stk = []
            for i in range(len(matrix) - 1, -1, -1):
                while len(stk) > 0 and right[i][j] <= right[stk[-1]][j]:
                    stk.pop()
                if len(stk) == 0:
                    down[i][j] = len(matrix) - i
                else:
                    down[i][j] = stk[-1] - i
                stk.append(i)
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res = max(res, right[i][j] * (up[i][j] + down[i][j] - 1))
        return res