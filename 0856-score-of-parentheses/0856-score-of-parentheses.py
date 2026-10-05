class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        res = []
        order = 0
        for c in s:
            if c == '(':
                order += 1
            else:
                if len(res) == 0 or order > res[-1][1]:
                    res.append((1, order))
                elif res[-1][1] == order:
                    res.append((res.pop()[0] + 1, order))
                else:
                    cur = res.pop()[0] * 2
                    if len(res) == 0 or order > res[-1][1]:
                        res.append((cur, order))
                    elif res[-1][1] == order:
                        res.append((res.pop()[0] + cur, order))
                order -= 1
        return res[0][0]