def solve(nums1: List[int], nums2: List[int], dp: List[List[int]], i: int, j: int) -> int:
    if i == len(nums1) or j == len(nums2):
        return float('-inf')
    if dp[i][j] == -1:
        dp[i][j] = float('-inf')
        dp[i][j] = max(dp[i][j], nums1[i] * nums2[j] + max(0, solve(nums1, nums2, dp, i + 1, j + 1)))
        dp[i][j] = max(dp[i][j], solve(nums1, nums2, dp, i, j + 1))
        dp[i][j] = max(dp[i][j], solve(nums1, nums2, dp, i + 1, j))
    return dp[i][j]
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[-1 for _ in range(len(nums2))] for _ in range(len(nums1))]
        return solve(nums1, nums2, dp, 0, 0)
        