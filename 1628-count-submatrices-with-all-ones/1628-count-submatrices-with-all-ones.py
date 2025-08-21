class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        res = 0
        widths = []
        for row in mat:
            width = []
            for cell in row:
                if cell == 1:
                    if len(width) == 0:
                        width.append(1)
                    else:
                        width.append(width[-1] + 1)
                else:
                    width.append(0)
            widths.append(width)
            for j in range(len(width)):
                minWidth = width[j]
                for k in range(len(widths) - 1, -1, -1):
                    minWidth = min(minWidth, widths[k][j])
                    if minWidth == 0:
                        break;
                    res += minWidth
        return res
