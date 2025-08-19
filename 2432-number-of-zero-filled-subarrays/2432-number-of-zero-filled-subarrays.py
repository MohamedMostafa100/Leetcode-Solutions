class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        res = 0
        length = 0
        for num in nums:
            if num == 0:
                length += 1
            else:
                length = 0
            res += length
        return res
        