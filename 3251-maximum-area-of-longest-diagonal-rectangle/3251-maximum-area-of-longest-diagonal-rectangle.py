class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        maxArea = 0
        maxDiag = 0
        for d in dimensions:
            diag = sqrt(d[0]**2 + d[1]**2)
            if diag > maxDiag:
                maxArea = d[0] * d[1]
                maxDiag = diag
            elif diag == maxDiag:
                maxArea = max(maxArea, d[0] * d[1])
        return maxArea