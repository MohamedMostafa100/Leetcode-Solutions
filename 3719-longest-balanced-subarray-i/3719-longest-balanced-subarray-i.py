class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        res = 0
        for i in range(len(nums) - 1):
            even = set()
            odd = set()
            for j in range(i, len(nums)):
                if nums[j] % 2 == 0:
                    even.add(nums[j])
                else:
                    odd.add(nums[j])
                if len(even) == len(odd):
                    res = max(res, j - i + 1)
        return res