class Solution:
    def reverse(self, x: int) -> int:
        res = 0
        temp = abs(x)
        while temp != 0:
            res = res * 10 + (temp % 10)
            if (res > 2 ** 31 and x < 0) or res > 2**31 - 1 :
                return 0
            temp //= 10
        return res if x > 0 else -res