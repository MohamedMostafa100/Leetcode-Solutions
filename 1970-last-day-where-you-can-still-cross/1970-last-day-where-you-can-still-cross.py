class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        parent = [i for i in range(len(cells) + 2)]
        rank = [0 for _ in range(len(cells) + 2)]
        grid = [[False for _ in range(col)] for _ in range(row)]
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        top = len(cells)
        bottom = top + 1
        def findParent(x: int) -> int: 
            while x != parent[x]:
                x = parent[x]
            return x
        def unite(x: int, y: int) -> None:
            x = findParent(x)
            y = findParent(y)
            if x == y:
                return
            if rank[x] > rank[y]:
                parent[y] = x
            elif rank[y] > rank[x]:
                parent[x] = y
            else:
                parent[x] = y
                rank[y] += 1
        for idx, cell in enumerate(cells[::-1]):
            r = cell[0] - 1
            c = cell[1] - 1
            cid = r * col + c
            grid[r][c] = True
            if r == 0:
                unite(cid, top)
            elif r == row - 1:
                unite(cid, bottom)
            for i,j in dirs:
                newR = r + i
                newC = c + j
                newCID = newR * col + newC
                if newR >= 0 and newR < row and newC >= 0 and newC < col and grid[newR][newC]:
                    unite(cid, newCID)
            if findParent(top) == findParent(bottom):
                return len(cells) - idx - 1
        return 0
            
