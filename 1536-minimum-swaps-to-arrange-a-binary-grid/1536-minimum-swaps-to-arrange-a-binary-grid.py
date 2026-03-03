class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        res = 0
        pos = [-1 for _ in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid) - 1, -1, -1):
                if grid[i][j] == 1:
                    pos[i] = j
                    break
        for i in range(len(grid)):
            found = False
            for j in range(i, len(grid)):
                if pos[j] <= i:
                    found = True
                    for k in range(j, i, -1):
                        pos[k], pos[k - 1] = pos[k - 1], pos[k]
                        res += 1
                    break
            if not found:
                return -1
        return res
