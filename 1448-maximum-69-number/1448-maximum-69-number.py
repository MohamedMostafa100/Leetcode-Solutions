class Solution:
    def maximum69Number (self, num: int) -> int:
        n = num
        toAdd = 0
        i = 1
        while n > 0:
            if n % 10 == 6:
                toAdd = 3 * i
            n //= 10
            i *= 10
        return num + toAdd
        