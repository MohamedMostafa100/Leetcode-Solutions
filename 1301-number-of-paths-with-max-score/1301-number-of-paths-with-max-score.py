class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        m = len(board)
        n = len(board[0])
        dp1 = [[-1 for _ in range(n)] for _ in range(m)]
        dp2 = [[-1 for _ in range(n)] for _ in range(m)]
        dp1[0][0] = 0
        dp2[0][0] = 1
        def solve1(i: int, j: int) -> int:
            if i < 0 or j < 0 or board[i][j] == 'X':
                return float('-inf') / 2
            if dp1[i][j] == -1:
                dp1[i][j] = float('-inf') / 2
                toAdd = 0
                if board[i][j] != 'S':
                    toAdd = int(board[i][j])
                dp1[i][j] = max(dp1[i][j], solve1(i - 1, j) + toAdd)
                dp1[i][j] = max(dp1[i][j], solve1(i, j - 1) + toAdd)
                dp1[i][j] = max(dp1[i][j], solve1(i - 1, j - 1) + toAdd)
            return dp1[i][j]
        def solve2(i: int, j: int, curSum: int) -> int:
            if i < 0 or j < 0 or board[i][j] == 'X' or dp1[i][j] != curSum:
                return 0
            if dp2[i][j] == -1:
                dp2[i][j] = 0
                if board[i][j] != 'S':
                    curSum -= int(board[i][j])
                dp2[i][j] = (dp2[i][j] + solve2(i - 1, j, curSum)) % 1000000007
                dp2[i][j] = (dp2[i][j] + solve2(i, j - 1, curSum)) % 1000000007
                dp2[i][j] = (dp2[i][j] + solve2(i - 1, j - 1, curSum)) % 1000000007
            return dp2[i][j] % 1000000007
        maxSum = max(0, solve1(m - 1, n - 1))
        maxSumPaths = solve2(m - 1, n - 1, maxSum)
        return [maxSum, maxSumPaths]