class Solution:
    def countPartitions(self, nums: List[int]) -> int:
        res = 0
        sumR = sum(nums)
        sumL = 0
        for num in nums[:-1]:
            sumR -= num
            sumL += num
            if abs(sumL - sumR) % 2 == 0:
                res += 1
        return res