def case1(s: str, x: str) -> int:
    res = 0
    i = 0
    while i < len(s):
        cnt = 0
        while i < len(s) and s[i] == x:
            cnt += 1
            res = max(res, cnt)
            i += 1
        i += 1
    return res
def case2(s: str, x: str, y: str) -> int:
    res = 0
    i = 0
    while i < len(s):
        diff = {}
        diff[0] = i - 1
        xCnt = 0
        yCnt = 0
        while i < len(s) and (s[i] == x or s[i] == y):
            if s[i] == x:
                xCnt += 1
            else:
                yCnt += 1
            d = xCnt - yCnt
            if d in diff:
                res = max(res, i - diff[d])
            else:
                diff[d] = i
            i += 1
        i += 1
    return res
def case3(s: str) -> int:
    res = 0
    diff = {}
    a = 0
    b = 0
    c = 0
    d1 = 0
    d2 = 0
    diff[(d1, d2)] = -1
    for i in range(len(s)):
        if s[i] == 'a':
            a += 1
        elif s[i] == 'b':
            b += 1
        else:
            c += 1
        d1 = a - b
        d2 = a - c
        if (d1, d2) in diff:
            res = max(res, i - diff[(d1, d2)])
        else:
            diff[(d1, d2)] = i
    return res 

class Solution:
    def longestBalanced(self, s: str) -> int:
        res = 0
        res = max(res, case1(s, 'a'))
        res = max(res, case1(s, 'b'))
        res = max(res, case1(s, 'c'))
        res = max(res, case2(s, 'a', 'b'))
        res = max(res, case2(s, 'a', 'c'))
        res = max(res, case2(s, 'b', 'c'))
        res = max(res, case3(s))
        return res