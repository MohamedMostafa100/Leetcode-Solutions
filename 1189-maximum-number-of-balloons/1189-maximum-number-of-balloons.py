class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        res = float('inf')
        cond = "balon"
        freqs = {c : 0 for c in cond}
        for c in text:
            if c in cond:
                freqs[c] += 1
        for c in cond:
            if c == 'l' or c == 'o':
                res = min(res, freqs[c] // 2)
            else:
                res = min(res, freqs[c])
        return res
