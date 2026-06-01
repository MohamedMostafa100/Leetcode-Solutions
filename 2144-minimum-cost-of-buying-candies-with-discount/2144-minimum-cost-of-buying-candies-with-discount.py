class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        res = 0
        cost.sort()
        i = len(cost) - 1
        while i >= 0:
            if i - 2 >= 0:
                res += cost[i] + cost[i - 1]
                i -= 3
            else:
                res += cost[i]
                i -= 1
        return res