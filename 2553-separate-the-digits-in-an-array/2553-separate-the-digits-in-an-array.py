class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res = []
        def sep(x: int) -> List[int]:
            res = []
            while x > 0:
                rem = x % 10
                res.append(rem)
                x //= 10
            res.reverse()
            return res
        for num in nums:
            res.extend(sep(num))
        return res
        