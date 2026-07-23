class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        return 2 ** int(log2(n) + 1) if n >= 3 else n