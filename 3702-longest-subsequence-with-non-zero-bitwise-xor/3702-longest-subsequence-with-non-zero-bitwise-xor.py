class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        xorSum = 0
        nonZero = False
        for num in nums:
            xorSum ^= num
            if num:
                nonZero = True
        return n if xorSum > 0 else n - 1 if nonZero else 0