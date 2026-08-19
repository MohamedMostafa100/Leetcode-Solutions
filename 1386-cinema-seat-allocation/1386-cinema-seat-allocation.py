class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        res = 2 * n
        rows = {}
        for r, c in reservedSeats:
            if r not in rows:
                rows[r] = 0
            if c == 2 or c == 3:
                rows[r] |= 4
            elif c == 4 or c == 5:
                rows[r] |= 4
                rows[r] |= 2
            elif c == 6 or c == 7:
                rows[r] |= 2
                rows[r] |= 1
            elif c == 8 or c == 9:
                rows[r] |= 1
        for r, off in rows.items():
            if off == 7:
                res -= 2
            elif off >= 1:
                res -= 1
        return res