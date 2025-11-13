class Solution:
    def maxOperations(self, s: str) -> int:
        res = 0
        onesCount = 0
        i = 0
        while i < len(s):
            if s[i] == '1':
                onesCount += 1
            else:
                while i + 1 < len(s) and s[i + 1] != '1':
                    i += 1
                res += onesCount    
            i += 1    
        return res