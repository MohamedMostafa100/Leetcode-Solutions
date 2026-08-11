class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        res = nums[0]
        n = len(nums)
        found = set(nums)
        idx = 1
        while idx < n and nums[idx] == nums[idx - 1] + 1:
            res += nums[idx]
            idx += 1
        while res in found:
            res += 1
        return res
