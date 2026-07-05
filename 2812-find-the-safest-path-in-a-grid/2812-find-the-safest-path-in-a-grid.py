class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        res = float('inf')
        m = len(grid)
        n = len(grid[0])
        q = deque()
        pq = []
        visited = set()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    grid[i][j] = 0
                    q.append((i, j))
                else:
                    grid[i][j] = -1
        while len(q) > 0:
            i, j = q.popleft()
            if j - 1 >= 0 and grid[i][j - 1] == -1:
                grid[i][j - 1] = grid[i][j] + 1
                q.append((i, j - 1))
            if j + 1 < n and grid[i][j + 1] == -1:
                grid[i][j + 1] = grid[i][j] + 1
                q.append((i, j + 1))
            if i - 1 >= 0 and grid[i - 1][j] == -1:
                grid[i - 1][j] = grid[i][j] + 1
                q.append((i - 1, j))
            if i + 1 < m and grid[i + 1][j] == -1:
                grid[i + 1][j] = grid[i][j] + 1
                q.append((i + 1, j))
        heapq.heappush(pq, (-grid[0][0], 0))
        while len(pq) > 0:
            cost, node = heapq.heappop(pq)
            if node in visited:
                continue
            res = min(res, -cost)
            visited.add(node)
            i = node // n
            j = node % n
            if i == m - 1 and j == n - 1:
                break
            if j - 1 >= 0:
                newNode = n * i + (j - 1)
                if newNode not in visited:
                    heapq.heappush(pq, (-grid[i][j - 1], newNode))
            if j + 1 < n:
                newNode = n * i + (j + 1)
                if newNode not in visited:
                    heapq.heappush(pq, (-grid[i][j + 1], newNode))
            if i - 1 >= 0:
                newNode = n * (i - 1) + j
                if newNode not in visited:
                    heapq.heappush(pq, (-grid[i - 1][j], newNode))
            if i + 1 < m:
                newNode = n * (i + 1) + j
                if newNode not in visited:
                    heapq.heappush(pq, (-grid[i + 1][j], newNode))
        return res