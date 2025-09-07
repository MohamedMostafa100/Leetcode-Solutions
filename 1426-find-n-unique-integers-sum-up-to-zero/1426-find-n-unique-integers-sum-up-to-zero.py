class Solution:
    def sumZero(self, n: int) -> List[int]:
        res = []
        s = 1
        while len(res) < n - 1:
            res.append(s)
            res.append(-s)
            s += 1
        if len(res) < n:
            res.append(0)
        return res