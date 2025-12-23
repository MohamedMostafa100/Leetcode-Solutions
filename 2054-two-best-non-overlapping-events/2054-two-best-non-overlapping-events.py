class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        res = 0
        maxVal = 0
        events = sorted(events)
        pq = []
        for event in events:
            while len(pq) > 0 and event[0] > pq[0][0]:
                maxVal = max(maxVal, pq[0][1])
                heapq.heappop(pq)
            heapq.heappush(pq, (event[1], event[2]))
            res = max(res, event[2] + maxVal)
        return res