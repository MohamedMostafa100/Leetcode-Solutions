class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        maxArea = 0
        maxDiag = 0
        for l,w in dimensions:
            diag = sqrt(l**2 + w**2)
            if diag > maxDiag:
                maxArea = l * w
                maxDiag = diag
            elif diag == maxDiag:
                maxArea = max(maxArea, l * w)
        return maxArea