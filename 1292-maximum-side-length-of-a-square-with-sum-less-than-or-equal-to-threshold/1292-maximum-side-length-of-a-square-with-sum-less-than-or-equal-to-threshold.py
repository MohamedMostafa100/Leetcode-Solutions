class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        res = 0
        n = len(mat)
        m = len(mat[0])
        rowSum = [[0 for _ in range(m)] for _ in range(n)]
        l = 0
        r = min(n, m) + 1
        for i in range(n):
            tot = 0
            for j in range(m):
                tot += mat[i][j]
                rowSum[i][j] = tot
        def checkSquare(row: int, col: int, side: int) -> bool:
            if row + side - 1 >= n or col + side - 1 >= m:
                return False
            tot = 0
            for i in range(row, row + side):
                if col > 0:
                    tot += rowSum[i][col + side - 1] - rowSum[i][col - 1]
                else:
                    tot += rowSum[i][col + side - 1]
                if tot > threshold:
                    return False
            return True
        while l < r:
            mid = (l + r) // 2
            flag = False
            for i in range(n):
                for j in range(m):
                    if checkSquare(i, j, mid):
                        flag = True
                        break
                if flag:
                    break
            if flag:
                res = mid
                l = mid + 1
            else:
                r = mid
        return res
