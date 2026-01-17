class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        res = 0
        for i in range(len(bottomLeft)):
            for j in range(i + 1, len(bottomLeft)):
                intX = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0])
                intY = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1])
                if intX > 0 and intY > 0:
                    res = max(res, min(intX, intY) * min(intX, intY))
        return res