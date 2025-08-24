class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        res = 0
        before = 0
        after = 0
        for num in nums:
            if num == 1:
                after += 1
            else:
                res = max(res, before + after)
                before = after
                after = 0
        res = max(res, before + after)
        return res if res != len(nums) else res - 1
