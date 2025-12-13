class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        res = []
        lines = {"electronics", "grocery", "pharmacy", "restaurant"}
        for i in range(len(code)):
            if all(c.isalnum() or c == '_' for c in code[i]) and bool(code[i]) and businessLine[i] in lines and isActive[i]:
                res.append((code[i], businessLine[i]))
        res = sorted(res, key=lambda x: (x[1], x[0]))
        return [x[0] for x in res]