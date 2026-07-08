class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        intervals.sort()
        curS = intervals[0][0]
        curE = intervals[0][1]
        for s, e in intervals[1:]:
            if (s >= curS and s <= curE) or (curE >= s and curE <= e):
                curS = min(s, curS)
                curE = max(e, curE)
            else:
                res.append([curS, curE])
                curS = s
                curE = e
        res.append([curS, curE])
        return res
