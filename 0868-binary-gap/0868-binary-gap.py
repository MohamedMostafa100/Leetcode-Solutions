class Solution:
    def binaryGap(self, n: int) -> int:
        res = 0
        mask = 1
        prev = -1
        for i in range(32):
            if mask & n:
                if prev != -1:
                    res = max(res, i - prev)
                prev = i
            mask <<= 1
        return res