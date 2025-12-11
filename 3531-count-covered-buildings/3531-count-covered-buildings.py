class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        res = 0
        minX = [float('inf') for _ in range(n + 1)]
        maxX = [1 for _ in range(n + 1)]
        minY = [float('inf') for _ in range(n + 1)]
        maxY = [1 for _ in range(n + 1)]
        for building in buildings:
            x = building[0]
            y = building[1]
            minX[y] = min(minX[y], x)
            maxX[y] = max(maxX[y], x)
            minY[x] = min(minY[x], y)
            maxY[x] = max(maxY[x], y)
        for building in buildings:
            x = building[0]
            y = building[1]
            if x > minX[y] and x < maxX[y] and y > minY[x] and y < maxY[x]:
                res += 1
        return res