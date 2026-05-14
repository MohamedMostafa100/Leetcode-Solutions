class Solution:
    def isGood(self, nums: List[int]) -> bool:
        n = len(nums) - 1
        count = len(nums)
        for num in nums:
            absNum = abs(num)
            if absNum >= 1 and absNum <= n:
                if absNum == n:
                    if nums[n - 1] > 0:
                        nums[n - 1] *= -1
                        count -= 1
                    elif nums[n] > 0:
                        nums[n] *= -1
                        count -= 1
                    else:
                        return False
                else:
                    if nums[absNum - 1] > 0:
                        nums[absNum - 1] *= -1
                        count -= 1
                    else:
                        return False
            else:
                return False
        return True if count == 0 else False