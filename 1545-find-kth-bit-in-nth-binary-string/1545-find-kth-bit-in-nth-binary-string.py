class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if n == 1:
            return '0'
        length = (1 << n) - 1
        if k - 1 == length // 2:
            return '1'
        elif k - 1 < length // 2:
            return self.findKthBit(n - 1, k)
        return '0' if self.findKthBit(n - 1, length - k + 1) == '1' else '1'