class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        if s[-1] != '0':
            return False
        dp = [0 for _ in range(len(s) + 1)]
        dp[-2] = 1
        for i in range(len(s) - 2, -1, -1):
            if s[i] == '1':
                dp[i] = dp[i + 1]
            else:
                start = i + minJump
                if start >= len(s):
                    dp[i] = dp[i + 1]
                    continue
                end = min(i + maxJump, len(s) - 1) + 1
                if dp[start] - dp[end] >= 1:
                    dp[i] = dp[i + 1] + 1
                else:
                    dp[i] = dp[i + 1]
        if dp[0] - dp[1] == 1:
            return True
        return False
            