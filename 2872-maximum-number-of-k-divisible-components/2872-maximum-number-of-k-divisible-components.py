class Solution:
    def dfs(self, adjList: List[List[int]], values: List[int], cur: int, k: int, parent: int) -> tuple[int, int]:
        summ = values[cur]
        splits = 0
        for edge in adjList[cur]:
            if edge != parent:
                search = self.dfs(adjList, values, edge, k, cur)
                summ += search[0]
                splits += search[1]
        if summ % k == 0:
            splits += 1
            summ = 0
        return summ, splits
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        adjList = [[] for _ in range(n)]
        for edge in edges:
            adjList[edge[0]].append(edge[1])
            adjList[edge[1]].append(edge[0])
        return self.dfs(adjList, values, 0, k, -1)[1]