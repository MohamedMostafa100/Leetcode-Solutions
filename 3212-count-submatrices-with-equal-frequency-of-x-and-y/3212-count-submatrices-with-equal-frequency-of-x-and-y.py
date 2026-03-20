class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        res = 0
        pre = [(0, False) for _ in range(len(grid))]
        for j in range(len(grid[0])):
            tot = 0
            x = False
            for i in range(len(grid)):
                if grid[i][j] == 'X':
                    f, _ = pre[i]
                    pre[i] = (f + 1, True)
                elif grid[i][j] == 'Y':
                    f, s = pre[i]
                    pre[i] = (f - 1, s)
                tot += pre[i][0]
                x |= pre[i][1]
                if x and not tot:
                    res += 1
        return res