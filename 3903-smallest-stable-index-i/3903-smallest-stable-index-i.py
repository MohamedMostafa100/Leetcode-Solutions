class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        res = len(nums)
        pre = [0 for _ in range(len(nums))]
        minNum = float('inf')
        curMax = 0
        curMin = float('inf')
        r = len(nums) - 1
        for l in range(len(nums)):
            curMax = max(curMax, nums[l])
            curMin = min(curMin, nums[r])
            pre[l] += curMax
            pre[r] -= curMin
            if l >= r:
                if pre[l] <= k:
                    res = min(res, l)
                if pre[r] <= k:
                    res = min(res, r)
            r -= 1
        return res if res != len(nums) else -1