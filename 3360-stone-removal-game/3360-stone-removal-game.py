class Solution:
    def canAliceWin(self, n: int) -> bool:
        tot = (55 - n) * 2
        x = ceil((-1 + sqrt(1 + 4 * tot)) / 2)
        return x % 2 == 1