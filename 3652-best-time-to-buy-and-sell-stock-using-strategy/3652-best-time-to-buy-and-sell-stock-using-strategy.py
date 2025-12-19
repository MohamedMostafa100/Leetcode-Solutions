class Solution:
    def maxProfit(self, prices: List[int], strategy: List[int], k: int) -> int:
        res = 0
        tot = 0
        windowTot = 0
        profit = 0
        l = 0
        pre = [0 for _ in range(len(prices))]
        for r in range(len(prices)):
            tot += (prices[r] * strategy[r])
            windowTot += (prices[r] * strategy[r])
            if r >= k - 1:
                pre[r] = windowTot
                windowTot -= (prices[l] * strategy[l])
                l += 1
        res = tot
        l = 0
        for r in range(len(prices)):
            if r >= (k / 2):
                profit += prices[r]
            if r - l + 1 == k:
                res = max(res, tot - pre[r] + profit)
                profit -= prices[l + (k // 2)]
                l += 1
        return res
