class Solution:
    def containsCycle(self, grid: List[List[str]]) -> bool:
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        def dfs(i: int , j: int, prev: str, dir: int) -> int:
            if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]) or grid[i][j] != prev:
                return False
            if visited[i][j]:
                return True
            else:
                visited[i][j] = True
                if dir != 1 and dfs(i + 1, j, grid[i][j], 0):
                    return True
                if dir != 0 and dfs(i - 1, j, grid[i][j], 1):
                    return True
                if dir != 3 and dfs(i, j + 1, grid[i][j], 2):
                    return True
                if dir != 2 and dfs(i, j - 1, grid[i][j], 3):
                    return True
            return False
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if not visited[i][j] and dfs(i, j, grid[i][j], -1):
                    return True
        return False