def solve(s1: str, s2: str, dp: List[List[int]], i: int, j: int) -> int:
    if i == len(s1) or j == len(s2):
        rem = 0
        while i < len(s1):
            rem += ord(s1[i])
            i += 1
        while j < len(s2):
            rem += ord(s2[j])
            j += 1
        return rem
    if dp[i][j] == -1:
        dp[i][j] = float('inf')
        if s1[i] == s2[j]:
            dp[i][j] = min(dp[i][j], solve(s1, s2, dp, i + 1, j + 1))
        else:
            dp[i][j] = min(dp[i][j], solve(s1, s2, dp, i + 1, j) + ord(s1[i]))
            dp[i][j] = min(dp[i][j], solve(s1, s2, dp, i, j + 1) + ord(s2[j]))
    return dp[i][j]
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        dp = [[-1 for _ in range(len(s2))] for _ in range(len(s1))]
        return solve(s1, s2, dp, 0, 0)
        