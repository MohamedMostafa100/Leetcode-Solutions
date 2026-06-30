class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res = 0
        l = 0
        chars = [0 for _ in range(3)]
        charCount = 0
        for r in range(len(s)):
            chars[ord(s[r]) - ord('a')] += 1
            if chars[ord(s[r]) - ord('a')] == 1:
                charCount += 1
            while charCount == 3:
                res += len(s) - r
                chars[ord(s[l]) - ord('a')] -= 1
                if chars[ord(s[l]) - ord('a')] == 0:
                    charCount -= 1
                l += 1
        return res