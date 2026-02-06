class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        res = 1
        l = 0
        nums.sort()
        for r in range(len(nums)):
            while nums[l] * k < nums[r]:
                l += 1
            res = max(res, r - l + 1)
        return len(nums) - res