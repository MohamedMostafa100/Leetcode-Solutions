class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        res = 0
        n = len(nums)
        l = 0
        freqs = {}
        for r in range(n):
            freqs[nums[r]] = freqs.get(nums[r], 0) + 1
            while freqs[nums[r]] > k:
                freqs[nums[l]] -= 1
                l += 1
            res = max(res, r - l + 1)
        return res