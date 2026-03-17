class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        res = 0
        m = len(matrix)
        n = len(matrix[0])
        prevHeights = []
        for i in range(m):
            heights = []
            seen = [False for _ in range(n)]
            for j in range(len(prevHeights)):
                if matrix[i][prevHeights[j][1]] == 1:
                    heights.append([prevHeights[j][0] + 1, prevHeights[j][1]])
                    seen[prevHeights[j][1]] = True
            for j in range(n):
                if not seen[j] and matrix[i][j] == 1:
                    heights.append([1, j])
            for j in range(len(heights)):
                res = max(res, heights[j][0] * (j + 1))
            prevHeights = heights
        return res