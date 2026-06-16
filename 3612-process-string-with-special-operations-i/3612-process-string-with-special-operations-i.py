class Solution:
    def processStr(self, s: str) -> str:
        res = []
        for ch in s:
            if ch == '*':
                if len(res) > 0:
                    res.pop()
            elif ch == '#':
                res += res
            elif ch == '%':
                res.reverse()
            else:
                res.append(ch)
        return ''.join(res)