class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        res = 1
        length = 1
        for i in range(1, len(prices)):
            if prices[i - 1] - prices[i] == 1:
                length += 1
            else:
                length = 1
            res += length
        return res