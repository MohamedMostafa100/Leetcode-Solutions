class Solution:
    def numOps(self, s: int, e: int) -> int:
        ops = 0
        pow = 1
        base = 4
        last = s
        while base <= e:
            if base > last:
                ops += (base - last) * pow
                last = base
            base <<= 2
            pow += 1
        ops += (e - last + 1) * pow
        return ceil(ops / 2)
    def minOperations(self, queries: List[List[int]]) -> int:
        res = 0
        for s, e in queries:
            res += self.numOps(s, e)
        return res
        