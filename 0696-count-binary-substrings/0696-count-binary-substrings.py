class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        res = 0
        first = 0
        second = 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                second += 1
            else:
                res += min(first, second)
                first = second
                second = 1
        return res + min(first, second)

