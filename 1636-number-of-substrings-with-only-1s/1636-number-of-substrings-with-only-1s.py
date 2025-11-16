class Solution:
    def numSub(self, s: str) -> int:
        res = 0
        n = 0
        for ch in s:
            if ch == '1':
                n += 1
            else:
                res += ((n * (n + 1) / 2) % 1000000007)
                n = 0
        res += ((n * (n + 1) / 2) % 1000000007)
        return int(res)