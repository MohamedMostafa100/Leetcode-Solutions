class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        def sumDig(num: int) -> int:
            res = 0
            while num > 0:
                res += num % 10
                num //= 10
            return res
        for i in range(len(nums)):
            if i == sumDig(nums[i]):
                return i
        return -1