class Solution:
    def maxArea(self, height: List[int]) -> int:
        area = 0
        l = 0
        r = len(height) - 1
        while l < r:
            area = max(area, (r - l) * min(height[l], height[r]))
            if height[l] > height[r]:
                r -= 1
            elif height[l] < height[r]:
                l += 1
            else:
                l += 1
                r -= 1
        return area