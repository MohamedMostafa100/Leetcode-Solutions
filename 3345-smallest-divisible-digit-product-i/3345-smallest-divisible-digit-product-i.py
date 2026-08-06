class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        def numProd(num: int) -> int:
            prod = 1
            while num > 0:
                prod *= (num % 10)
                num //= 10
            return prod
        for i in range(n, n + 10):
            if numProd(i) % t == 0:
                return i
        return 0