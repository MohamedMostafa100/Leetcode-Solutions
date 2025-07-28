class Solution:
    def solve(self, nums: List[int], idx: int, cur: int, maxOr: int) -> int:
        if idx == len(nums):
            return 1 if cur == maxOr else 0
        count = 0
        count += self.solve(nums, idx + 1, cur | nums[idx], maxOr)
        count += self.solve(nums, idx + 1, cur, maxOr)
        return count


    def countMaxOrSubsets(self, nums: List[int]) -> int:
        maxOr = 0
        for num in nums:
            maxOr |= num
        res = self.solve(nums, 0, 0, maxOr)
        return res

        