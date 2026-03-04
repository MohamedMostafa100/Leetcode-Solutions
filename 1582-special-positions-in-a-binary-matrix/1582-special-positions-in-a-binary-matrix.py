class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        res = 0
        row = [0 for _ in range(len(mat))]
        col = [0 for _ in range(len(mat[0]))]
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j]:
                    row[i] += 1
                    col[j] += 1
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] and row[i] == 1 and col[j] == 1:
                    res += 1
        return res