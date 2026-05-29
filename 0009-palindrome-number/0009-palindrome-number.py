class Solution:
    def isPalindrome(self, x: int) -> bool:
        rev = 0
        n = x
        while n > 0:
            rev = rev * 10 + (n % 10)
            n //= 10
        if rev == x:
            return True
        return False
