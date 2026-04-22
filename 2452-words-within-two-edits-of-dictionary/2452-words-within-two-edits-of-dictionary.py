class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        res = []
        def checkDist(s: str, t: str) -> bool:
            dist = 0
            for i in range(len(s)):
                if s[i] != t[i]:
                    dist += 1
                if dist > 2:
                    return False
            return True
        for q in queries:
            for d in dictionary:
                if checkDist(q, d):
                    res.append(q)
                    break
        return res