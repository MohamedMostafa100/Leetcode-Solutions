class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        res = []
        def resetBit(num: int) -> int:
            modified = 0
            mask = 2
            i = 1
            while True:
                if mask & num == 0:
                    modified = ~(1 << (i - 1)) & num
                    break
                mask <<= 1
                i += 1
            return modified
        for num in nums:
            if num == 2:
                res.append(-1)
                continue
            res.append(resetBit(num))
        return res
