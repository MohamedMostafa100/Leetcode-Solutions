class Solution:
    def countCompleteComponents(self, n: int, edges: list[list[int]]) -> int:
        res = 0
        graph = [[] for _ in range(n)]
        nodes = set()
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        def bfs(node: int) -> List[int]:
            q = [node]
            visited = {node}
            component = [node]
            idx = 0
            while idx < len(q):
                cur = q[idx]
                idx += 1
                for neighbor in graph[cur]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        component.append(neighbor)
                        q.append(neighbor)
            return component
        for i in range(n):
            if i not in nodes:
                component = bfs(i)
                connected = True
                for node in component:
                    if len(graph[node]) != len(component) - 1:
                        connected = False
                        break
                if connected:
                    res += 1
                for node in component:
                    nodes.add(node)
        return res