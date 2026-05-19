class Solution:
    def minJumps(self, arr: List[int]) -> int:
        res = 0
        n = len(arr)
        idxs = {}
        visited = [False for _ in range(n)]
        bfs = deque()
        for i in range(n):
            if arr[i] in idxs:
                idxs[arr[i]].append(i)
            else:
                idxs[arr[i]] = [i]
        bfs.append((0, 0))
        while len(bfs) > 0:
            node, dist = bfs.popleft()
            if node == n - 1:
                res = dist
                break
            visited[node] = True
            for nextNode in idxs[arr[node]]:
                if not visited[nextNode]:
                    bfs.append((nextNode, dist + 1))
            idxs[arr[node]].clear()
            if node > 0 and not visited[node - 1]:
                bfs.append((node - 1, dist + 1))
            if node < n - 1 and not visited[node + 1]:
                bfs.append((node + 1, dist + 1))
        return res