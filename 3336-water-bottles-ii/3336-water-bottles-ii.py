class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        res = numBottles
        empty = res
        while empty >= numExchange:
            res += 1
            empty -= numExchange - 1
            numExchange += 1
        return res