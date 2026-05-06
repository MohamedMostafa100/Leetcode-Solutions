class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        m = len(boxGrid)
        n = len(boxGrid[0])
        res = [['.' for _ in range(m)] for _ in range(n)]
        for i in range(m):
            restPos = n - 1
            for j in range(n - 1, -1, -1):
                if boxGrid[i][j] == '#':
                    res[restPos][m - i - 1] = '#'
                    restPos -= 1
                elif boxGrid[i][j] == '*':
                    res[j][m - i - 1] = '*'
                    restPos = j - 1
        return res