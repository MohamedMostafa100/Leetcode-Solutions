class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0 for _ in range(n)]
        stk = []
        for log in logs:
            ops = log.split(':')
            i, s, ts = int(ops[0]), ops[1], int(ops[2])
            if s == 'end':
                res[i] += ts - stk.pop()[1] + 1
                if len(stk) > 0:
                    stk[-1][1] = ts + 1
            else:
                if len(stk) > 0:
                    res[stk[-1][0]] += ts - stk[-1][1]
                stk.append([i, ts])
        return res
