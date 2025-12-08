class Solution:
    def countTriples(self, n: int) -> int:
        res = 0
        for i in range(1, n):
            for j in range(i + 1, n):
                c = sqrt(i**2 + j**2)
                if c == ceil(c) and c <= n:
                    res += 2
        return res