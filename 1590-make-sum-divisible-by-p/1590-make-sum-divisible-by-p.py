class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        res = len(nums)
        mp = {}
        totalRem = 0
        rem = 0
        for i, num in enumerate(nums):
            totalRem = (totalRem + num) % p
            if totalRem == 0:
                res = min(res, len(nums) - i - 1)
                if res == 0:
                    return 0
        for i, num in enumerate(nums):
            sufRem = (totalRem - rem) % p
            if (p - sufRem) % p in mp:
                res = min(res, i - mp[(p - sufRem) % p] - 1)
            rem = (rem + num) % p
            mp[rem] = i
            if sufRem == 0:
                res = min(res, i)
        if res == len(nums):
            return -1
        return res