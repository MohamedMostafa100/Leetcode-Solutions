class Solution:
    def minimumDeletions(self, s: str) -> int:
        res = 0
        a = 0
        suffB = [0 for _ in range(len(s))]
        for i in range(len(s) - 1, -1, -1):
            if s[i] == 'b':
                suffB[i] += 1
            if i < len(s) - 1:
                suffB[i] += suffB[i + 1]
        for i in range(len(s)):
            if s[i] == 'a':
                a += 1
            res = max(res, a + suffB[i])
        return len(s) - res