class Solution:
    def solve(self, nums: List[int], dp: List[List[int]], i: int, mod: int) -> int:
        if i == len(nums):
            if mod == 0:
                return 0
            else:
                return float('-inf')
        if dp[i][mod] == -1:
            dp[i][mod] = 0
            dp[i][mod] = max(self.solve(nums, dp, i + 1, mod), self.solve(nums, dp, i + 1, (mod + nums[i]) % 3) + nums[i])
        return dp[i][mod]
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [[-1 for _ in range(3)] for _ in range(len(nums))]
        return self.solve(nums, dp, 0, 0)
        