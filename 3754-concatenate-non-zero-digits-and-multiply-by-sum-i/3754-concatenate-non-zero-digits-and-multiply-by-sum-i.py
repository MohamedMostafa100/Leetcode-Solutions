class Solution:
    def sumAndMultiply(self, n: int) -> int:
        num = 0
        multiplier = 1
        tot = 0
        while n > 0:
            rem = n % 10
            if rem > 0:
                num = rem * multiplier + num
                tot += rem
                multiplier *= 10
            n //= 10
        return num * tot