class Solution:
    def minimumSumSubarray(self, nums: List[int], l: int, r: int) -> int:
        res = float('inf')
        for win in range(l, r + 1):
            cur = 0
            s = 0
            for e in range(len(nums)):
                cur += nums[e]
                if e - s + 1 == win:
                    res = min(res, cur) if cur > 0 else res
                    cur -= nums[s]
                    s += 1
        return -1 if res == float('inf') else res
