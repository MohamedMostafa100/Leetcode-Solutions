class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res = ""
        fact = 1
        for i in range(2, n):
            fact *= i
        used = [str(i) for i in range(1, n + 1)]
        start = 1
        for i in range(1, n):
            idx = (k - start) // fact
            res += used[idx]
            used.pop(idx)
            start += fact * idx
            fact //= (n - i)
        res += used[0]
        return res