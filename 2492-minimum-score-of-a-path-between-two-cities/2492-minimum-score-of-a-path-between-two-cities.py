class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        res = float('inf')
        graph = [[] for _ in range(n)]
        q = []
        visited = set()
        for u, v, d in roads:
            graph[u - 1].append((v - 1, d))
            graph[v - 1].append((u - 1, d))
        q.append(0)
        visited.add(0)
        while len(q) > 0:
            node = q.pop()
            for v, d in graph[node]:
                res = min(res, d)
                if v not in visited:
                    q.append(v)
                    visited.add(v)
        return res