class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n = len(mat)
        for k in range(4):
            match = True
            newMat = [[0 for _ in range(n)] for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    if mat[i][j] != target[i][j]:
                        match = False
                    newMat[j][n - i - 1] = mat[i][j]
            if match:
                return True
            mat = newMat
        return False