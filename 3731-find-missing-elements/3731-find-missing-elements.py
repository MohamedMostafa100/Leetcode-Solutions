class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        res = []
        rng = [False for _ in range(101)]
        mn = 100
        mx = 1
        for num in nums:
            mn = min(mn, num)
            mx = max(mx, num)
            rng[num] = True
        for i in range(mn + 1, mx):
            if not rng[i]:
                res.append(i)
        return res
