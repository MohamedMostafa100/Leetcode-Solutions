class Solution:
    def solve(self, grid: List[List[int]], dp: List[List[List[List[int]]]], i: int, j: int, dir: int, turn: int, prev: int) -> int:
        if i < 0 or j < 0 or i == len(grid) or j == len(grid[0]):
            return 0
        if (prev == 1 and grid[i][j] != 2) or (prev == 2 and grid[i][j] != 0) or (prev == 0 and grid[i][j] != 2):
            return 0
        if dp[i][j][dir][turn] == -1:
            dp[i][j][dir][turn] = 1
            if dir == 0:
                noTurn = self.solve(grid, dp, i - 1, j - 1, 0, turn, grid[i][j])
                doTurn = 0
                if not turn:
                    doTurn = self.solve(grid, dp, i - 1, j + 1, 1, 1, grid[i][j])
                dp[i][j][dir][turn] += max(noTurn, doTurn)
            elif dir == 1:
                noTurn = self.solve(grid, dp, i - 1, j + 1, 1, turn, grid[i][j])
                doTurn = 0
                if not turn:
                    doTurn = self.solve(grid, dp, i + 1, j + 1, 2, 1, grid[i][j])
                dp[i][j][dir][turn] += max(noTurn, doTurn)
            elif dir == 2:
                noTurn = self.solve(grid, dp, i + 1, j + 1, 2, turn, grid[i][j])
                doTurn = 0
                if not turn:
                    doTurn = self.solve(grid, dp, i + 1, j - 1, 3, 1, grid[i][j])
                dp[i][j][dir][turn] += max(noTurn, doTurn)
            elif dir == 3:
                noTurn = self.solve(grid, dp, i + 1, j - 1, 3, turn, grid[i][j])
                doTurn = 0
                if not turn:
                    doTurn = self.solve(grid, dp, i - 1, j - 1, 0, 1, grid[i][j])
                dp[i][j][dir][turn] += max(noTurn, doTurn)
        return dp[i][j][dir][turn]

    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        res = 0
        dp = [[[[-1 for turn in range(2)] for dir in range(4)] for j in range(len(grid[0]))] for i in range(len(grid))]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    res = max(res, 1 + self.solve(grid, dp, i - 1, j - 1, 0, 0, 1))
                    res = max(res, 1 + self.solve(grid, dp, i - 1, j + 1, 1, 0, 1))
                    res = max(res, 1 + self.solve(grid, dp, i + 1, j + 1, 2, 0, 1))
                    res = max(res, 1 + self.solve(grid, dp, i + 1, j - 1, 3, 0, 1))
        return res