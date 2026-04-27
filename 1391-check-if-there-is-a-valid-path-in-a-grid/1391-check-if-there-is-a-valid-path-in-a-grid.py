class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        visited = [[False for _ in range(len(grid[0]))] for _ in range(len(grid))]
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        pipes = {1: [2, 3], 2: [0, 1], 3: [0, 3], 4: [0, 2], 5: [1, 3], 6: [1, 2]}
        def getDir(cur: int, direction: int) -> int:
            if direction == -2:
                return pipes[cur][0]
            elif direction == -1:
                return pipes[cur][1]
            elif direction == 0:
                if pipes[cur][0] == 1:
                    return pipes[cur][1]
                elif pipes[cur][1] == 1:
                    return pipes[cur][0]
            elif direction == 1:
                if pipes[cur][0] == 0:
                    return pipes[cur][1]
                elif pipes[cur][1] == 0:
                    return pipes[cur][0]
            elif direction == 2:
                if pipes[cur][0] == 3:
                    return pipes[cur][1]
                elif pipes[cur][1] == 3:
                    return pipes[cur][0]
            else:
                if pipes[cur][0] == 2:
                    return pipes[cur][1]
                elif pipes[cur][1] == 2:
                    return pipes[cur][0]
            return -1
        def dfs(i: int, j: int, direction: int) -> bool:
            if i < 0 or i == len(grid) or j < 0 or j == len(grid[0]) or (visited[i][j] and (i > 0 or j > 0)):
                return False
            direction = getDir(grid[i][j], direction)
            if direction == -1:
                return False
            if i == len(grid) - 1 and j == len(grid[0]) - 1:
                return True
            visited[i][j] = True
            if dfs(i + dirs[direction][0], j + dirs[direction][1], direction):
                return True
            return False
        return dfs(0, 0, -2) or dfs(0, 0, -1)

            