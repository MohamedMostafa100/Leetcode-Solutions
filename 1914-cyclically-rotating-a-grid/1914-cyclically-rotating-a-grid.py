class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        layers = min(m // 2, n // 2)
        prem = 2 * m + 2 * n - 4
        for l in range(layers):
            steps = k % prem
            idx = (prem - steps) % prem
            shifted = [0 for _ in range(prem)]
            for j in range(l, n - l - 1):
                shifted[idx] = grid[l][j]
                idx = (idx + 1) % prem
            for i in range(l, m - l - 1):
                shifted[idx] = grid[i][n - l - 1]
                idx = (idx + 1) % prem
            for j in range(n - l - 1, l, -1):
                shifted[idx] = grid[m - l - 1][j]
                idx = (idx + 1) % prem
            for i in range(m - l - 1, l, -1):
                shifted[idx] = grid[i][l]
                idx = (idx + 1) % prem
            idx = 0 
            for j in range(l, n - l - 1):
                grid[l][j] = shifted[idx]
                idx += 1
            for i in range(l, m - l - 1):
                grid[i][n - l - 1] = shifted[idx]
                idx += 1
            for j in range(n - l - 1, l, -1):
                grid[m - l - 1][j] = shifted[idx]
                idx += 1
            for i in range(m - l - 1, l, -1):
                grid[i][l] = shifted[idx]
                idx += 1
            prem -= 8
        return grid