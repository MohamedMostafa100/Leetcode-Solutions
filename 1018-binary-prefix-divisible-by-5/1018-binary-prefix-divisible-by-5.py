class Solution:
    def prefixesDivBy5(self, nums: List[int]) -> List[bool]:
        res = []
        cur = 0
        for num in nums:
            if num == 1:
                cur += 1
            if cur % 5 == 0:
                res.append(True)
            else:
                res.append(False)
            cur <<= 1
        return res