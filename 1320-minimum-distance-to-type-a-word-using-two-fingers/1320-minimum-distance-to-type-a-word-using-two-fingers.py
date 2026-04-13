class Solution:
    def minimumDistance(self, word: str) -> int:
        dp = [[[-1 for _ in range(len(word))] for _ in range(27)] for _ in range(27)]
        def getDist(x: int, y: int) -> int:
            x -= 1
            y -= 1
            if x == -1:
                return 0
            xX = x % 6
            xY = x // 6
            yX = y % 6
            yY = y // 6
            return abs(xX - yX) + abs(xY - yY)
        def solve(i: int, j: int, k: int) -> int:
            if k == len(word):
                return 0
            if dp[i][j][k] == -1:
                dp[i][j][k] = float('inf')
                nextChar = ord(word[k]) - ord('A') + 1
                dp[i][j][k] = min(dp[i][j][k], solve(nextChar, j, k + 1) + getDist(i, nextChar))
                dp[i][j][k] = min(dp[i][j][k], solve(i, nextChar, k + 1) + getDist(j, nextChar))
            return dp[i][j][k]
        return solve(0, 0, 0)

