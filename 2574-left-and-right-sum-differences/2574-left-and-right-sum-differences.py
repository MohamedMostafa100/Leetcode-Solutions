class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        res = [0 for _ in range(len(nums))]
        leftSum = 0
        rightSum = 0
        for i in range(len(nums)):
            res[i] = abs(res[i] - leftSum)
            leftSum += nums[i]
            res[-i - 1] = abs(res[-i - 1] - rightSum)
            rightSum += nums[-i - 1]
        return res