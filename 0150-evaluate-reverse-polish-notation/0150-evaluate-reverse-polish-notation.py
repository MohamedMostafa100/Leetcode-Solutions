class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stk = []
        for token in tokens:
            if token == '+':
                op = stk[-2] + stk[-1]
                stk.pop()
                stk.pop()
                stk.append(op)
            elif token == '-':
                op = stk[-2] - stk[-1]
                stk.pop()
                stk.pop()
                stk.append(op)
            elif token == '*':
                op = stk[-2] * stk[-1]
                stk.pop()
                stk.pop()
                stk.append(op)
            elif token == '/':
                op = int(stk[-2] / stk[-1])
                stk.pop()
                stk.pop()
                stk.append(op)
            else:
                stk.append(int(token))
        return stk[-1]
                