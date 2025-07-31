class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res = set()
        curOrs = {0}
        for x in arr:
            nextOrs = {x | y for y in curOrs}
            nextOrs.add(x)
            res.update(nextOrs)
            curOrs = nextOrs
        return len(res)
        