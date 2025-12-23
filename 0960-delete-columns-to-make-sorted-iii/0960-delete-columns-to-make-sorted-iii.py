class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        dp = [1 for _ in range(len(strs[0]))]
        for i in range(len(strs[0]) - 2, -1, -1):
            for j in range(i + 1, len(strs[0])):
                violation = False
                for k in range(len(strs)):
                    if strs[k][i] > strs[k][j]:
                        violation = True
                        break
                if not violation:
                    dp[i] = max(dp[i], dp[j] + 1)
        return len(strs[0]) - max(dp)