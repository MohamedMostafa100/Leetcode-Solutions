class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        robots = [(positions[i], healths[i], directions[i], i) for i in range(len(positions))]
        stk = []
        robots.sort()
        for p, h, d, i in robots:
            if d == 'R':
                stk.append([p, h, d, i])
            else:
                while len(stk) > 0 and stk[-1][2] == 'R' and stk[-1][1] < h:
                    healths[stk[-1][3]] = 0
                    healths[i] -= 1
                    h -= 1
                    stk.pop()
                if len(stk) == 0 or stk[-1][2] == 'L':
                    stk.append([p, h, d, i])
                elif stk[-1][1] > h:
                    stk[-1][1] -= 1
                    healths[stk[-1][3]] -= 1
                    healths[i] = 0
                else:
                    healths[stk[-1][3]] = 0
                    healths[i] = 0
                    stk.pop()
        res = [h for h in healths if h > 0]
        return res
