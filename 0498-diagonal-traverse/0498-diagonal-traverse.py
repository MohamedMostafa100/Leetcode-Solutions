class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        res = []
        dir = 1
        i = 0
        j = 0
        while i < len(mat) and j < len(mat[0]):
            res.append(mat[i][j])
            if dir == 1:
                if i - 1 >= 0 and j + 1 < len(mat[0]):
                    i -= 1
                    j += 1
                else:
                    if j != len(mat[0]) - 1:
                        j += 1
                    else:
                        i += 1
                    dir = 0
            else:
                if i + 1 < len(mat) and j - 1 >= 0:
                    i += 1
                    j -= 1
                else:
                    if i != len(mat) - 1:
                        i += 1
                    else:
                        j += 1
                    dir = 1
        return res
