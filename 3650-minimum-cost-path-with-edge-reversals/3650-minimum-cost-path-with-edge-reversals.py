class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for e in edges:
            graph[e[0]].append((e[1], e[2]))
            graph[e[1]].append((e[0], 2 * e[2]))
        def dijk() -> int:
            res = [-1 for _ in range(n)]
            pq = [(0, 0)]
            visited = set()
            while len(pq) > 0:
                cost, source = heapq.heappop(pq)
                if source in visited:
                    continue
                visited.add(source)
                for dest, travelCost in graph[source]:
                    if res[dest] == -1 or cost + travelCost < res[dest]:
                        res[dest] = cost + travelCost
                        heapq.heappush(pq, (cost + travelCost, dest))
            return res[-1]
        return dijk()