class Solution:
    def trailingZeroes(self, n: int) -> int:
        def countDiv(n: int, x: int) -> int:
            res = 0
            while n % x == 0:
                res += 1
                n //= x
            return res
        fives = 0
        twos = 0
        for i in range(n, 0, -1):
            if i % 5 == 0:
                fives += countDiv(i, 5)
            if i % 2 == 0:
                twos += countDiv(i, 2)
        return min(fives, twos)