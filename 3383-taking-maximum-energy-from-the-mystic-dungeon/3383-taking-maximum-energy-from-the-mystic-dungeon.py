class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        res = float('-inf')
        dp = []
        dp.append(energy[0])
        for i in range(1, len(energy)):
            if i - k >= 0:
                dp.append(max(energy[i], dp[i - k] + energy[i]))
            else:
                dp.append(energy[i])
            if len(energy) - i <= k:
                res = max(res, dp[i])
        return res