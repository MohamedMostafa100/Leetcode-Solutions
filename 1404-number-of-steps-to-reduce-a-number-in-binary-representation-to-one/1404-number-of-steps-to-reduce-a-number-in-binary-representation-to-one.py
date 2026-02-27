class Solution:
    def numSteps(self, s: str) -> int:
        res = 0
        def inc() -> None:
            nonlocal s
            strList = list(s)
            i = len(s) - 1
            while i >= 0 and strList[i] == '1':
                strList[i] = '0'
                i -= 1
            if i >= 0:
                strList[i] = '1'
            else:
                strList = ['1'] + strList
            s = ''.join(strList)
        def divide() -> None:
            nonlocal s
            s = s[:-1]
        while len(s) > 1:
            if s[-1] == '1':
                inc()
            else:
                divide()
            res += 1
        if s[0] == '0':
            res += 1
        return res