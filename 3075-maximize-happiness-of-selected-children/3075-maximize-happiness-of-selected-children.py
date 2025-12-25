class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        res = 0
        sub = 0
        happiness = sorted(happiness, reverse=True)
        for h in happiness:
            if k == 0 or h - sub <= 0:
                break
            res += h - sub
            k -= 1
            sub += 1
        return res
