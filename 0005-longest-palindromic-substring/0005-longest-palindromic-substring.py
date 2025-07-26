class Solution:
    def expand(self, s: str, l: int, r: int):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return l + 1, r - 1
    def longestPalindrome(self, s: str) -> str:
        maxLength = 1
        start = 0
        end = 0
        for i in range(len(s)):
            l, r = self.expand(s, i, i + 1)
            if r - l + 1 > maxLength:
                start = l
                end = r
                maxLength = r - l + 1
            l, r = self.expand(s, i, i)
            if r - l + 1 > maxLength:
                start = l
                end = r 
                maxLength = r - l + 1
        return s[start:end + 1]

        