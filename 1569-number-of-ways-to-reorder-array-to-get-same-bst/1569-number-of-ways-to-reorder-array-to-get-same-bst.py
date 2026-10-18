class Solution:
    def numOfWays(self, nums: list[int]) -> int:
        mod = 10 ** 9 + 7
        def solve(arr: list[int]) -> int:
            if len(arr) <= 2:
                return 1
            left = [num for num in arr if num < arr[0]]
            right = [num for num in arr if num > arr[0]]
            return (comb(len(arr) - 1, len(left)) * solve(left) * solve(right)) % mod
        return solve(nums) - 1