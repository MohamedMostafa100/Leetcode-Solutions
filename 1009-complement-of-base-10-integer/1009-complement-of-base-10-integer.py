class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        mask = 1 << 31
        while mask > 0 and  not (mask & n):
            mask >>= 1
        while mask > 0:
            n ^= mask
            mask >>= 1
        return n