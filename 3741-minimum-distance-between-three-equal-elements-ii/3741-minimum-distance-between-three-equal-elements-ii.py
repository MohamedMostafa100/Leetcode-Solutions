class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        res = float('inf')
        numIdxs = {}
        for i, num in enumerate(nums):
            if num not in numIdxs:
                numIdxs[num] = []
            numIdxs[num].append(i)
        for num, idxs in numIdxs.items():
            if len(idxs) >= 3:
                i = 0
                for k in range(2, len(idxs)):
                    res = min(res, 2 * (idxs[k] - idxs[i]))
                    i += 1
        return -1 if res == float('inf') else res