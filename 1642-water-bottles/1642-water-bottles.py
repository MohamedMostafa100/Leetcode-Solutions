class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        res = numBottles
        empty = numBottles
        while empty >= numExchange:
            res += (empty // numExchange) 
            empty = (empty // numExchange) + (empty % numExchange)
        return res