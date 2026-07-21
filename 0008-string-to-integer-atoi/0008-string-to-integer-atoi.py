class Solution:
    def myAtoi(self, s: str) -> int:
        res = 0
        sign = 1
        s = s.strip()
        for i, ch in enumerate(s):
            if ch.isdigit():
                res = res * 10 + int(ch)
                if sign * res >= 2**31 - 1:
                    return 2**31 - 1
                elif sign * res <= -2**31:
                    return -2**31
            else:
                if i == 0:
                    if s[i] == '-':
                        sign = -1
                        continue
                    elif s[i] == '+':
                        continue
                return sign * res
        return sign * res