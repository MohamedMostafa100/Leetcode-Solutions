class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        res = []
        powers = []
        mask = 1
        for i in range(0, 32):
            if mask & n:
                powers.append(1 << i)
            mask <<= 1
        for i in range(1, len(powers)):
            powers[i] = powers[i] * powers[i - 1]
        for query in queries:
            if query[0] == 0:
                res.append(powers[query[1]] % 1000000007)
            else:
                res.append((powers[query[1]] // powers[query[0] - 1]) % 1000000007)
        return res
        