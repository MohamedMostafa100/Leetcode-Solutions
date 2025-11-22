class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        res = 0
        chs = set()
        toMatch = ord('a')
        first = -1
        last = -1
        while toMatch <= ord('z'):
            l = 0
            r = len(s) - 1
            while l <= r and (first == -1 or last == -1):
                if first == -1 and s[l] == chr(toMatch):
                    first = l
                elif first == -1:
                    l += 1
                if last == -1 and s[r] == chr(toMatch):
                    last = r
                elif last == -1:
                    r -= 1
            if first > -1 and last > -1:
                for c in s[first + 1 : last]:
                    chs.add(c)
            res += len(chs)
            chs = set()
            first = -1
            last = -1
            toMatch += 1
        return res