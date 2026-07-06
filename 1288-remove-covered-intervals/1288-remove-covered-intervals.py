class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key= lambda x: (x[0], -x[1]))
        res = len(intervals)
        maxEnd = intervals[0][1]
        for s, e in intervals[1:]:
            if e <= maxEnd:
                res -= 1
            maxEnd = max(maxEnd, e)
        return res