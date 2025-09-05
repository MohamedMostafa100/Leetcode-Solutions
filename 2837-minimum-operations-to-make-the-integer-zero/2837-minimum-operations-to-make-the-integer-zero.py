class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        res = 1
        num = num1
        while True:
            num -= num2
            if num < res:
                return -1
            elif res >= num.bit_count():
                return res
            res += 1