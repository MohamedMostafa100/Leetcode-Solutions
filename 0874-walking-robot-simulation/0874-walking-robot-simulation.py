class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        res = 0
        x = 0
        y = 0
        curDir = 0
        obs = {obX + obY * 60013 for obX, obY in obstacles}
        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for c in commands:
            if c == -1:
                curDir += 1
                curDir %= 4
                continue
            elif c == -2:
                curDir -= 1
                curDir %= 4
                continue
            for j in range(c):
                if ((x + dirs[curDir][0]) + 60013 * (y + dirs[curDir][1])) in obs:
                    break
                x += dirs[curDir][0]
                y += dirs[curDir][1]
                res = max(res, x * x + y * y)
        return res
