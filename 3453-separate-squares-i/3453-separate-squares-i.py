def calcArea(squares: List[List[int]], y: float) -> float:
    area = 0
    for sq in squares:
        area += sq[2] * max(0, min(sq[2], y - sq[1]))
    return area

class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        totArea = 0
        minY = float('inf')
        maxY = 0
        for sq in squares:
            totArea += sq[2] * sq[2]
            minY = min(minY, sq[1])
            maxY = max(maxY, sq[1] + sq[2])
        eps = 10**-5
        while abs(maxY - minY) > eps:
            mid = (maxY + minY) / 2
            area = calcArea(squares, mid)
            if area * 2 >= totArea:
                maxY = mid
            else:
                minY = mid
        return maxY

        