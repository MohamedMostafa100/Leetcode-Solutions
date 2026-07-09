class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        res = []
        unions = [0]
        curId = 0
        for i in range(1, len(nums)):
            if nums[i] - nums[i - 1] > maxDiff:
                curId += 1
            unions.append(curId)
        for u, v in queries:
            if unions[u] == unions[v]:
                res.append(True)
            else:
                res.append(False)
        return res

        