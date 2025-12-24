class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        res = 0
        tot = sum(apple)
        capacity = sorted(capacity, reverse=True)
        for c in capacity:
            res += 1
            if tot - c <= 0:
                break
            tot -= c
        return res