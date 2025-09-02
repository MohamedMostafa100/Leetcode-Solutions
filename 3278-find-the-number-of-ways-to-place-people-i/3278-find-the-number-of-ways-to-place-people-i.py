class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        res = 0
        points = sorted(points, key=lambda point: (point[0], -point[1]))
        for i in range(len(points)):
            lowerLimit = -1
            for j in range(i + 1, len(points)):
                if points[j][1] < points[i][1]:
                    if points[j][1] > lowerLimit:
                        res += 1
                        lowerLimit = points[j][1]
                elif points[j][1] == points[i][1]:
                    res += 1
                    break
        return res
