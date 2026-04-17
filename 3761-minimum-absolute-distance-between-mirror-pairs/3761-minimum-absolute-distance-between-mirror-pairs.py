class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        def reverse(x: int) -> int:
            res = 0
            while x > 0:
                res = res * 10 + (x % 10)
                x //= 10
            return res
        res = len(nums)
        pos = {}
        pos[nums[-1]] = len(nums) - 1
        for i in range(len(nums) - 2, -1, -1):
            rev = reverse(nums[i])
            if rev in pos:
                res = min(res, pos[rev] - i)
            pos[nums[i]] = i
        return -1 if res == len(nums) else res