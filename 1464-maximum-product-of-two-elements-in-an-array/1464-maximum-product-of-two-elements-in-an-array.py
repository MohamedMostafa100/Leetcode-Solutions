class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = 0
        mx = nums[0]
        for num in nums[1:]:
            res = max(res, (mx - 1) * (num - 1))
            mx = max(mx, num)
        return res