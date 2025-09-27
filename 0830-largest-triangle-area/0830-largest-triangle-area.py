class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        maxArea = 0
        for i in range(len(points) - 2):
            for j in range(len(points) - 1):
                for k in range(len(points)):
                    area = 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1]))
                    maxArea = max(maxArea, area)
        return maxArea