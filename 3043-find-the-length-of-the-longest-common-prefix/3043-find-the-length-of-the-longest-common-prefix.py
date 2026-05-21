class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        res = 0
        pres = set()
        for a in arr1:
            while a not in pres and a > 0:
                pres.add(a)
                a //= 10
        print(pres)
        for b in arr2:
            while b > 0:
                if b in pres:
                    res = max(res, len(str(b)))
                    break
                b //= 10
        return res