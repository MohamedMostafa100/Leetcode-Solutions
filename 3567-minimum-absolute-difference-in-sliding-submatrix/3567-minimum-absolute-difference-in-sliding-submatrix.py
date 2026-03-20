class Solution:
    def minAbsDiff(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        res = [[0 for _ in range(n - k + 1)] for _ in range(m - k + 1)]
        for i in range(m - k + 1):
            for j in range(n - k + 1):
                subGrid = []
                for r in range(i, i + k):
                    for c in range(j, j + k):
                        subGrid.append(grid[r][c])
                print(subGrid)
                subGrid.sort()
                kMin = float('inf')
                for t in range(1, len(subGrid)):
                    if subGrid[t] != subGrid[t - 1]:
                        kMin = min(kMin, subGrid[t] - subGrid[t - 1])
                if kMin != float('inf'):
                    res[i][j] = kMin
        return res
