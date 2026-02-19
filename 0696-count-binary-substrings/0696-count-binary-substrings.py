class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res = 0
        first = 1
        i = 1
        while i < len(s) and s[i] == s[i - 1]:
            first += 1
            i += 1
        while i < len(s):
            second = 1
            i += 1
            while i < len(s) and s[i] == s[i - 1]:
                second += 1
                i += 1
            res += min(first, second)
            first = second
        return res

