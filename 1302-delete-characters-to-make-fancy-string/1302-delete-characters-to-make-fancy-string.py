class Solution:
    def makeFancyString(self, s: str) -> str:
        res = s[0]
        vioCount = 0
        for c in s[1:]:
            if c == res[-1]:
                vioCount += 1
                if vioCount >= 2:
                    continue
            else:
                vioCount = 0
            res += c
        return res