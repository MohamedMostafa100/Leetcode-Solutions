class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        res = 0
        costs.sort()
        for cost in costs:
            if cost <= coins:
                res += 1
                coins -= cost
            else:
                return res
        return res