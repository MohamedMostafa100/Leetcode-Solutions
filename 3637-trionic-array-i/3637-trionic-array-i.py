class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        p = 0
        q = len(nums) - 1
        while p < q and (nums[p + 1] > nums[p] or nums[q - 1] < nums[q]):
            if nums[p + 1] > nums[p]:
                p += 1
            if nums[q - 1] < nums[q]:
                q -= 1
        if p == 0 or q == len(nums) - 1 or p >= q:
            return False
        for i in range(p + 1, q + 1):
            if nums[i] >= nums[i - 1]:
                return False
        return True