class Solution:
    def maxProduct(self, n: int) -> int:
        res = 0
        mx = 0
        while n > 0:
            rem = n % 10
            res = max(res, mx * rem)
            mx = max(mx, rem)
            n //= 10
        return res
