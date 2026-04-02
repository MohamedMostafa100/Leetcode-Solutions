class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        dp = [[[float('-inf') for _ in range(3)] for _ in range(len(coins[0]))] for _ in range(len(coins))]
        dp[-1][-1][2] = coins[-1][-1]
        if coins[-1][-1] >= 0:
            dp[-1][-1][0] = coins[-1][-1]
            dp[-1][-1][1] = coins[-1][-1]
        else:
            dp[-1][-1][0] = 0
            dp[-1][-1][1] = 0
        def solve(i: int, j: int, nt: int) -> int:
            if i == len(coins) or j == len(coins[0]):
                return -250000000
            if dp[i][j][nt] == float('-inf'):
                dp[i][j][nt] = -250000000
                dp[i][j][nt] = max(dp[i][j][nt], solve(i + 1, j, nt) + coins[i][j])
                dp[i][j][nt] = max(dp[i][j][nt], solve(i, j + 1, nt) + coins[i][j])
                if coins[i][j] < 0 and nt < 2:
                    dp[i][j][nt] = max(dp[i][j][nt], solve(i + 1, j, nt + 1))
                    dp[i][j][nt] = max(dp[i][j][nt], solve(i, j + 1, nt + 1))
            return dp[i][j][nt]
        return solve(0, 0, 0)