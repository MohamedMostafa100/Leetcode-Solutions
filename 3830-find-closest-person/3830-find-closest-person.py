class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        dist1 = abs(z - x)
        dist2 = abs(z - y)
        return 1 if dist1 < dist2 else 2 if dist1 > dist2 else 0