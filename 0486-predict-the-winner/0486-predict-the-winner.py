class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        if len(nums) % 2 == 0:
            return True
        def solve(i: int, j: int) -> int:
            if i == j:
                return nums[i]
            return max(nums[i] - solve(i + 1, j), nums[j] - solve(i, j - 1))
        return solve(0, len(nums) - 1) >= 0