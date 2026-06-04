class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        res = 0
        n = len(nums)
        for i in range(n):
            if nums[i] < 0 or nums[i] > n:
                nums[i] = 0
        for i in range(n):
            absIdx = abs(nums[i])
            if absIdx > 0 and absIdx <= n:
                if nums[absIdx - 1] > 0:
                    nums[absIdx - 1] *= -1
                elif nums[absIdx - 1] == 0:
                    nums[absIdx - 1] = -n - 1
                while res < n and nums[res] < 0:
                    res += 1
        return res + 1

                