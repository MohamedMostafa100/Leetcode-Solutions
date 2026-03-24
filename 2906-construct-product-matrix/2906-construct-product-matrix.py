class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        res = [[0 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        suf = [[1 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        prod = 1
        for i in range(len(grid) - 1, -1, -1):
            for j in range(len(grid[0]) - 1, -1, -1):
                suf[i][j] = prod
                prod = (prod * grid[i][j]) % 12345
        prod = 1
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                res[i][j] = (prod * suf[i][j]) % 12345
                prod = (prod * grid[i][j]) % 12345
        return res
        