class Solution:
    def judgeCircle(self, moves: str) -> bool:
        u = 0
        d = 0
        l = 0
        r = 0
        for m in moves:
            if m == 'U':
                u += 1
            elif m == 'D':
                d += 1
            elif m == 'L':
                l += 1
            else:
                r += 1
        if u == d and l == r:
            return True
        return False