class Solution:
    def rotatedDigits(self, n: int) -> int:
        res = 0
        dp = []
        for i in range(n + 1):
            if i < 10:
                if i == 0 or i == 1 or i == 8:
                    dp.append(1)
                elif i == 3 or i == 4 or i == 7:
                    dp.append(0)
                else:
                    dp.append(2)
                    res += 1
            else:
                dp.append(min(dp[i // 10] * dp[i % 10], 2))
                if dp[i] == 2:
                    res += 1
        return res