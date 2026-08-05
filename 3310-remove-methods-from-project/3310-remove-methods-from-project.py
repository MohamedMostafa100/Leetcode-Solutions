class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        toRemove = set()
        graph = [[] for _ in range(n)]
        visited = [False for _ in range(n)]
        for u, v in invocations:
            graph[u].append(v)
        def dfs(node: int) -> None:
            visited[node] = True
            toRemove.add(node)
            for v in graph[node]:
                if not visited[v]:
                    dfs(v)
        dfs(k)
        for u, v in invocations:
            if u not in toRemove and v in toRemove:
                return [i for i in range(n)]
        return [i for i in range(n) if i not in toRemove]
                