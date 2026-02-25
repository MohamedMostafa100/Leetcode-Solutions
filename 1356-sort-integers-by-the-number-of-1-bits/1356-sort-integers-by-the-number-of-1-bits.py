class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        bitsBuck = [[] for _ in range(16)]
        arr.sort()
        for a in arr:
            bitsBuck[a.bit_count()].append(a)
        res = sum(bitsBuck, [])
        return res