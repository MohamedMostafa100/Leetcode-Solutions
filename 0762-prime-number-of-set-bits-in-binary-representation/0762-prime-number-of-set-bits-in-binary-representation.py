class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        res = 0
        for i in range(left, right + 1):
            if i.bit_count() == 2 or i.bit_count() == 3 or i.bit_count() == 5 or i.bit_count() == 7 or i.bit_count() == 11 or i.bit_count() == 13 or i.bit_count() == 17 or i.bit_count() == 19:
                res += 1
        return res