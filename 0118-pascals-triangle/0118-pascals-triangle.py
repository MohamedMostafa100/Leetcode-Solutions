class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(numRows):
            res.append([1 for j in range(i + 1)])
            for j in range(1, len(res[i]) - 1):
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1]
        return res
        