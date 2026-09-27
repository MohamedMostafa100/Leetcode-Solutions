class Solution:
    def reverseParentheses(self, s: str) -> str:
        res = ""
        i = 0
        while i < len(s):
            if s[i] == '(':
                stk = ['(']
                i += 1
                while True:
                    if s[i] == ')':
                        cur = ""
                        while stk[-1] != '(':
                            cur += stk[-1]
                            stk.pop()
                        stk.pop()
                        for c in cur:
                            stk.append(c)
                        if len(stk) == 0 or stk[0] != '(':
                            break
                    else:
                        stk.append(s[i])
                    i += 1
                for c in stk:
                    res += c
            else:
                res += s[i]
            i += 1
        return res
