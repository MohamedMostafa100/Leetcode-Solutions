class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        res = 0
        nums = sorted(nums)
        for i in range(len(nums) // 2):
            res = max(res, nums[i] + nums[len(nums) - i - 1])
        return res