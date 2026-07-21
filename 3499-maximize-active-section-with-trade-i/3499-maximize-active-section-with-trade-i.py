class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        res = s.count('1')
        prev = 0
        cur = 0
        seqCount = 0
        maxLength = 0
        i = 0
        while i < len(s):
            if s[i] == '0':
                seqCount += 1
                while i < len(s) and s[i] == '0':
                    cur += 1
                    i += 1
                if seqCount >= 2:
                    maxLength = max(maxLength, cur + prev)
                prev = cur 
                cur = 0
            i += 1
        if seqCount >= 2:
            maxLength = max(maxLength, cur + prev)
        res += maxLength
        return res
