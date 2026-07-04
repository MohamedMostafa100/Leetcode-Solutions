class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        m = len(grid)
        n = len(grid[0])
        minHeap = []
        visited = set()
        heapq.heappush(minHeap, (grid[0][0], 0))
        while len(minHeap) > 0:
            cost, node = heapq.heappop(minHeap)
            if cost >= health:
                return False
            if node in visited:
                continue
            visited.add(node)
            i = node // n
            j = node % n
            if i == m - 1 and j == n - 1:
                return True
            if j - 1 >= 0:
                newNode = n * i + (j - 1)
                if newNode not in visited:
                    heapq.heappush(minHeap, (cost + grid[i][j - 1], newNode))
            if j + 1 < n:
                newNode = n * i + (j + 1)
                if newNode not in visited:
                    heapq.heappush(minHeap, (cost + grid[i][j + 1], newNode))
            if i - 1 >= 0:
                newNode = n * (i - 1) + j
                if newNode not in visited:
                    heapq.heappush(minHeap, (cost + grid[i - 1][j], newNode))
            if i + 1 < m:
                newNode = n * (i + 1) + j
                if newNode not in visited:
                    heapq.heappush(minHeap, (cost + grid[i + 1][j], newNode))
        return True
