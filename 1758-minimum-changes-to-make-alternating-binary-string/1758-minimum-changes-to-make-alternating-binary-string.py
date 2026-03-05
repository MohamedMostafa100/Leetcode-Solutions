class Solution:
    def minOperations(self, s: str) -> int:
        res1 = 0
        res2 = 0
        for i, ch in enumerate(s):
            if (ch == '1' and i % 2 == 0) or (ch == '0' and i % 2 == 1):
                res1 += 1
            else:
                res2 += 1
        return min(res1, res2)