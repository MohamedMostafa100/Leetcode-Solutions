class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        maxNum = max(nums)
        dp = [[[-1 for _ in range(maxNum + 1)] for _ in range(maxNum + 1)] for _ in range(len(nums))]
        def solve(i: int, g1: int, g2: int) -> int:
            if i == len(nums):
                if g1 > 0 and g2 > 0 and g1 == g2:
                    return 1
                return 0
            if dp[i][g1][g2] == -1:
                dp[i][g1][g2] = 0
                dp[i][g1][g2] = (dp[i][g1][g2] + solve(i + 1, nums[i] if g1 == 0 else gcd(g1, nums[i]), g2)) % 1000000007
                dp[i][g1][g2] = (dp[i][g1][g2] + solve(i + 1, g1, nums[i] if g2 == 0 else gcd(g2, nums[i]))) % 1000000007
                dp[i][g1][g2] = (dp[i][g1][g2] + solve(i + 1, g1, g2)) % 1000000007
            return dp[i][g1][g2] % 1000000007
        return solve(0, 0, 0)