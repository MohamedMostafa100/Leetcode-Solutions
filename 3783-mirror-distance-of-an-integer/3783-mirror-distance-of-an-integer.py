class Solution:
    def mirrorDistance(self, n: int) -> int:
        rev = 0
        x = n
        while x > 0:
            rev = rev * 10 + (x % 10)
            x //= 10
        return abs(rev - n)