class Solution:
    def makeFancyString(self, s: str) -> str:
        res = s[0]
        if len(s) > 1:
            res += s[1]
        for i in range(2, len(s)):
            if s[i] != s[i - 1] or s[i] != s[i - 2]:
                res += s[i]
        return res