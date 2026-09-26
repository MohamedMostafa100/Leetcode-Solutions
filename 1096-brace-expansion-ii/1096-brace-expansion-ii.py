class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        res = []
        ops = []
        cur = ""
        expression = '{' + expression + '}'
        for i, e in enumerate(expression):
            if e.isalpha():
                cur += e
                if i != 0 and expression[i - 1] == '}':
                    ops.append('*')
            elif e == '{':
                if i != 0 and (expression[i - 1].isalpha() or expression[i - 1] == '}'):
                    ops.append('*')
                if len(cur) > 0:
                    res.append({cur})
                ops.append('{')
                cur = ""
            elif e == ',':
                if len(cur) > 0:
                    res.append({cur})
                cur = ""
                while ops[-1] != '{' and ops[-1] != '+':
                    operand1 = res.pop()
                    operand2 = res.pop()
                    operation = ops.pop()
                    res.append({expr2 + expr1 for expr1 in operand1 for expr2 in operand2})
                ops.append('+')
            else:
                if len(cur) > 0:
                    res.append({cur})
                cur = ""
                while ops[-1] != '{':
                    operand1 = res.pop()
                    operand2 = res.pop()
                    operation = ops.pop()
                    if operation == '*':
                        res.append({expr2 + expr1 for expr1 in operand1 for expr2 in operand2})
                    else:
                        res.append(operand1.union(operand2))
                ops.pop()
        return sorted(list(res[0]))