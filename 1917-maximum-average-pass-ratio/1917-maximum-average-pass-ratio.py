class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        res = 0
        pq = []
        def priority(idx: int) -> float:
            return -(((classes[idx][0] + 1) / (classes[idx][1] + 1)) - (classes[idx][0] / classes[idx][1]))
        for i in range(len(classes)):
            heapq.heappush(pq, (priority(i), i))
        for i in range(extraStudents):
            topIdx = heappop(pq)[1]
            classes[topIdx][0] += 1
            classes[topIdx][1] += 1
            heapq.heappush(pq, (priority(topIdx), topIdx))
        for passed, total in classes:
            res += (passed / total) / len(classes)
        return res
        