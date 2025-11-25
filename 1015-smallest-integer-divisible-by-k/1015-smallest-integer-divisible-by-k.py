class Solution:
    def smallestRepunitDivByK(self, k: int) -> int:
        res = 1
        rems = set()
        lastRem = 1 % k
        rems.add(lastRem)
        while lastRem != 0:
            res += 1
            curRem = (((lastRem * 10) % k) + 1) % k
            if curRem in rems:
                res = -1
                break
            rems.add(curRem)
            lastRem = curRem
        return res
