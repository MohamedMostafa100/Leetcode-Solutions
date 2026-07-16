class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        res = 0
        n = len(nums)
        mx = 0
        prefixGcd = [gcd(max(mx, num), num) for num in nums if (mx := max(mx, num))]
        prefixGcd.sort()
        for i in range(n // 2):
            res += gcd(prefixGcd[i], prefixGcd[n - i - 1])
        return res