class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        res = 0
        n = len(arr)
        dp = [-1 for _ in range(n)]
        def solve(i: int) -> int:
            if dp[i] == -1:
                dp[i] = 1
                for j in range(i + 1, min(i + d + 1, n)):
                    if arr[i] <= arr[j]:
                        break
                    dp[i] = max(dp[i], solve(j) + 1)
                for j in range(i - 1, max(i - d - 1, -1), -1):
                    if arr[i] <= arr[j]:
                        break
                    dp[i] = max(dp[i], solve(j) + 1)
            return dp[i]
        for i in range(n):
            res = max(res, solve(i))
        return res