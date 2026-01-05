class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        tot = 0
        minNum = float('inf')
        containsZero = False
        oddNeg = False
        for row in matrix:
            for cell in row:
                if cell == 0:
                    containsZero = True
                else:
                    if cell < 0:
                        oddNeg = not oddNeg
                    minNum = min(minNum, abs(cell))
                tot += abs(cell)
        if oddNeg and  not containsZero:
            return tot - 2 * minNum
        return tot