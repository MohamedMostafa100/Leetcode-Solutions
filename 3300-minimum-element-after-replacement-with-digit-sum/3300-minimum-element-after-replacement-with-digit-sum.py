class Solution:
    def minElement(self, nums: List[int]) -> int:
        res = float('inf')
        for num in nums:
            tot = 0
            while num > 0:
                tot += (num % 10)
                num //= 10
            res = min(res, tot)
        return res