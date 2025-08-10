class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        s = str(n)
        s = "".join(sorted(s))
        i = 1
        while i < (1 << 31) - 1:
            cmp = str(i)
            cmp = "".join(sorted(cmp))
            if cmp == s:
                return True
            i <<= 1
        return False
