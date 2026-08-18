class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        if k == len(nums):
            return max(nums)
        res = -1
        freqs = {}
        for num in nums:
            freqs[num] = freqs.get(num, 0) + 1
        if k == 1:
            for x, f in freqs.items():
                if f == 1:
                    res = max(res, x)
        else:
            if freqs[nums[0]] == 1:
                res = max(res, nums[0])
            if freqs[nums[-1]] == 1:
                res = max(res, nums[-1])
        return res
        