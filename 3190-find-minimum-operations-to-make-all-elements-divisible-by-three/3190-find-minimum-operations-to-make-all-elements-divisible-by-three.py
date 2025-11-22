class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            res += min(num % 3, 3 - (num % 3))
        return res