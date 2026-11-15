class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        res = 0
        mod = 1000000007
        odd = 0
        even = 0 
        cur = 0
        for i in range(len(arr)):
            cur += arr[i]
            if cur & 1:
                res += 1
                if i > 0:
                    odd += 1
            elif i > 0:
                even += 1
        for i in range(1, len(arr)):
            if arr[i - 1] & 1:
                odd, even = even, odd
            res = (res + odd) % mod
            if arr[i] & 1:
                odd -= 1
            else:
                even -= 1
        return res