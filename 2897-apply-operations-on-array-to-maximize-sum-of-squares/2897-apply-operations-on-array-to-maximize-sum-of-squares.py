class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        res = 0
        mod = 1000000007
        bitCount = [0 for _ in range(31)]
        for num in nums:
            mask = 1
            for i in range(31):
                if num & mask:
                    bitCount[i] += 1
                mask <<= 1
        for i in range(k):
            cur = 0
            for j in range(31):
                if bitCount[j] > 0:
                    cur += (1 << j)
                    bitCount[j] -= 1
            res = (res + (cur * cur) % mod) % mod
        return res