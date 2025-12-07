class Solution:
    def countOdds(self, low: int, high: int) -> int:
        diff = (high - low) % 2
        if diff == 1:
            return (high - low) // 2 + 1
        return (high - low) // 2 + (low % 2)