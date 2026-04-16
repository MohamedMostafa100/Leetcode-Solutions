class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        res = []
        idxs = {}
        idxDists = {}
        for i, num in enumerate(nums):
            if num not in idxs:
                idxs[num] = []
            idxs[num].append(i)
        for idx in idxs.values():
            m = len(idx)
            if m > 1:
                for i, num in enumerate(idx):
                    if i == 0:
                        idxDists[num] = min(idx[1] - num, n - idx[-1] + num)
                    elif i == m - 1:
                        idxDists[num] = min(num - idx[-2], n - num + idx[0])
                    else:
                        idxDists[num] = min(num - idx[i - 1], idx[i + 1] - num)
        for q in queries:
            res.append(-1)
            if q in idxDists:
                res[-1] = idxDists[q]
        return res