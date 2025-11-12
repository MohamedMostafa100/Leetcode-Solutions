import numpy as np
class Solution:
    def solve(self, freqs: List[tuple[int, int]], dp: List[List[List[int]]], i: int, o: int, z: int, n: int, m: int) -> int:
        if i == len(freqs):
            return 0
        if dp[o][z][i] == -1:
            dp[o][z][i] = 0
            if o + freqs[i][0] <= n and z + freqs[i][1] <= m:
                dp[o][z][i] = max(dp[o][z][i], self.solve(freqs, dp, i + 1, o + freqs[i][0], z + freqs[i][1], n, m) + 1)
            dp[o][z][i] = max(dp[o][z][i], self.solve(freqs, dp, i + 1, o, z, n, m))
        return int(dp[o][z][i])
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        freqs = []
        dp = np.full((n + 1, m + 1, len(strs)), -1, dtype=int)
        for s in strs:
            o = 0
            z = 0
            for ch in s:
                if ch == '1':
                    o += 1
                else:
                    z += 1
            freqs.append((o, z))
        
        return self.solve(freqs, dp, 0, 0, 0, n, m)