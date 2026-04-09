class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        res = 0
        for l, r, k, v in queries:
            idx = l
            while idx <= r:
                nums[idx] = (nums[idx] * v) % 1000000007
                idx += k
        for num in nums:
            res ^= num
        return res