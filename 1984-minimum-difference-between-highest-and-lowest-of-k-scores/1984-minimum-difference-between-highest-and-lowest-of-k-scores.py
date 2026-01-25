class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        res = float('inf')
        l = 0
        nums = sorted(nums)
        for r in range(k - 1, len(nums)):
            res = min(res, nums[r] - nums[l])
            l += 1
        return res