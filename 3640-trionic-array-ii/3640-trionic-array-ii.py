class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        res = float('-inf')
        suffAdd = 0
        i = 1
        # Pass till we find the first strictly increasing sequence
        while nums[i] <= nums[i - 1]:
            i += 1
        while nums[i] > nums[i - 1]:
            suffAdd = max(nums[i - 1], suffAdd + nums[i - 1])
            i += 1
        while i < len(nums):
            decSum = nums[i - 1]
            while i < len(nums) and nums[i] < nums[i - 1]:
                decSum += nums[i]
                i += 1
            if i == len(nums):
                break
            elif nums[i] == nums[i - 1]:
                suffAdd = 0
                # Pass till we find the first strictly increasing sequence
                while i < len(nums) and nums[i] <= nums[i - 1]:
                    i += 1
                while i < len(nums) and nums[i] > nums[i - 1]:
                    suffAdd = max(nums[i - 1], suffAdd + nums[i - 1])
                    i += 1
                continue
            preAdd = nums[i]
            incSum = 0
            tempAdd = 0
            while i < len(nums) and nums[i] > nums[i - 1]:
                tempAdd = max(nums[i - 1], tempAdd + nums[i - 1])
                incSum += nums[i]
                preAdd = max(preAdd, incSum)
                i += 1
            res = max(res, suffAdd + decSum + preAdd)
            suffAdd = tempAdd
        return res