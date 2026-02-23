import heapq
from collections import defaultdict
class Solution:
    def minimumCost(self, source: str, target: str, original: list[str], changed: list[str], cost: list[int]) -> int:
        graph = defaultdict(lambda: defaultdict(lambda: float('inf')))
        for o, c, z in zip(original, changed, cost):
            graph[o][c] = min(graph[o][c], z)
        min_costs = {}
        def dijkstra(start_node):
            distances = {start_node: 0}
            pq = [(0, start_node)]
            while pq:
                curr_dist, u = heapq.heappop(pq)
                if curr_dist > distances.get(u, float('inf')):
                    continue
                for v, weight in graph[u].items():
                    if curr_dist + weight < distances.get(v, float('inf')):
                        distances[v] = curr_dist + weight
                        heapq.heappush(pq, (distances[v], v))
            return distances
        unique_chars = set(source)
        for char in unique_chars:
            min_costs[char] = dijkstra(char)
        total_cost = 0
        for s, t in zip(source, target):
            if s == t:
                continue
            if t in min_costs[s]:
                total_cost += min_costs[s][t]
            else:
                return -1    
        return total_cost