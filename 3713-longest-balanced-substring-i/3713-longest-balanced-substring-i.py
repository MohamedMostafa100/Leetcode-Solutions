class Solution:
    def longestBalanced(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            freqs = {}
            maxNum = 0
            maxs = 0
            for j in range(i, len(s)):
                freqs[s[j]] = freqs.get(s[j], 0) + 1
                if freqs[s[j]] > maxNum:
                    maxNum = freqs[s[j]]
                    maxs = 1
                elif freqs[s[j]] == maxNum:
                    maxs += 1
                if maxs == len(freqs):
                    res = max(res, j - i + 1)
        return res