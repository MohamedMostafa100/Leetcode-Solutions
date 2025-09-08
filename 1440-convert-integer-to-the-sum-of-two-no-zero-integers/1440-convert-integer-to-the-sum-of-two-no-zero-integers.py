class Solution:
    def containsZero(self, x: int) -> int:
        while x > 0:
            if x % 10 == 0:
                return True
            x //= 10
        return False 
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1, n // 2 + 1):
            if not self.containsZero(i) and not self.containsZero(n - i):
                return [i, n - i]
        return []
