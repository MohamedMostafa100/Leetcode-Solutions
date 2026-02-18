class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        x = (n >> 1) ^ n
        if x & (x + 1) == 0:
            return True
        return False 