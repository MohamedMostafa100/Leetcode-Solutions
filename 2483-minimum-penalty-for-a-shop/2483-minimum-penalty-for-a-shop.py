class Solution:
    def bestClosingTime(self, customers: str) -> int:
        res = 0
        y = 0
        n = 0
        yCur = 0
        nCur = 0
        for c in customers:
            if c == 'Y':
                y += 1
            else:
                n += 1
        pen = y
        for i,c in enumerate(customers):
            if c == 'Y':
                yCur += 1
            else:
                nCur += 1
            if (nCur + y - yCur) < pen:
                pen = nCur + y - yCur
                res = i + 1
        return res
