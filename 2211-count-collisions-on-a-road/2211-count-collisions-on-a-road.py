class Solution:
    def countCollisions(self, directions: str) -> int:
        res = 0
        stationary = False
        countR = 0
        for d in directions:
            if d == 'R':
                countR += 1
            elif d == 'S':
                if countR > 0:
                    res += countR
                    countR = 0
                stationary = True
            else:
                if countR > 0:
                    res += countR + 1
                    countR = 0
                    stationary = True
                elif stationary:
                    res += 1
        return res
