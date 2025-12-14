class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD = 1000000007
        segments = []
        pair = 0
        poss = 0
        for c in corridor:
            if c == 'S':
                if pair == 2:
                    segments.append(poss)
                    pair = 0
                    poss = 0
                pair += 1
            if pair == 2:
                poss += 1
        if pair == 0 or pair == 1:
            return 0
        res = reduce(lambda x, y: (x * y) % MOD, segments, 1)
        return res
        
