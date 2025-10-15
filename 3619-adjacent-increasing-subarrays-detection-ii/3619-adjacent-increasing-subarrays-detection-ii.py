class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        res = 0
        count = 1
        preCount = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                count += 1
            else:
                preCount = count
                count = 1
            res = max(res, min(preCount, count))
            res = max(res, count // 2)
        return res