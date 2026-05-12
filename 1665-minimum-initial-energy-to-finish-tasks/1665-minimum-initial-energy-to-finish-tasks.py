class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        res = 0
        tasks.sort(key= lambda x: -(x[1] - x[0]))
        tot = 0
        for a, m in tasks:
            diff = max(m - tot, 0)
            res += diff
            tot += diff - a
        return res