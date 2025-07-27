class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        res = 0
        for i in range(1, len(nums) - 1):
            b1 = i - 1
            b2 = i + 1
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                b2 += 1
                i += 1
            if b2 < len(nums):
                if (nums[i] > nums[b1] and nums[i] > nums[b2]) or (
                    nums[i] < nums[b1] and nums[i] < nums[b2]
                ):
                    res += 1
        return res
