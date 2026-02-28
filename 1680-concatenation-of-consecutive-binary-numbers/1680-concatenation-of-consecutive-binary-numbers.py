class Solution:
    def concatenatedBinary(self, n: int) -> int:
        res = 1
        MOD = 1000000007
        mask = 1 << 2
        shift = 2
        for i in range(2, n + 1):
            if mask & i:
                shift += 1
                mask <<= 1
            res = (((res << shift) % MOD) + i) % MOD
        return res