class Solution:
    def minFlips(self, s: str) -> int:
        res = 0
        freqs = [[0, 0], [0, 0]]
        for i in range(len(s)):
            if i % 2 == 0:
                freqs[0][int(s[i])] += 1
            else:
                freqs[1][int(s[i])] += 1
        if len(s) % 2 == 0:
            return len(s) - max(freqs[0][0] + freqs[1][1], freqs[0][1] + freqs[1][0])
        for i in range(len(s)):
            freqs[0][0], freqs[1][0] = freqs[1][0], freqs[0][0]
            freqs[0][1], freqs[1][1] = freqs[1][1], freqs[0][1]
            if s[i] == '0':
                freqs[0][0] += 1
                freqs[1][0] -= 1
            else:
                freqs[0][1] += 1
                freqs[1][1] -= 1
            res = max(res, freqs[0][0] + freqs[1][1], freqs[0][1] + freqs[1][0])
        return len(s) - res