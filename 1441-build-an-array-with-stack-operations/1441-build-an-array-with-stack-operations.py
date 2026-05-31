class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        x = 0
        for num in target:
            x += 1
            while x < num:
                res.append('Push')
                res.append('Pop')
                x += 1
            res.append('Push')
        return res