class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        res = 0
        pres = set()
        for a in arr1:
            num = str(a)
            for i in range(len(num)):
                pres.add(num[:i + 1])
        for b in arr2:
            num = str(b)
            for i in range(len(num)):
                if num[:i + 1] in pres:
                    res = max(res, i + 1)
        return res