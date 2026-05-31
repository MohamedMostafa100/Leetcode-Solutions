class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        dup = -1
        n = len(nums)
        tot = n * (n + 1) // 2
        cur = 0
        for i in range(n):
            num = abs(nums[i])
            if nums[num - 1] > 0:
                nums[num - 1] *= -1
                cur += num
            else:
                dup = num
        return [dup, tot - cur]