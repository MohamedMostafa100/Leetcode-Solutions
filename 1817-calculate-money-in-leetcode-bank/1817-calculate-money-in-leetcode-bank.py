class Solution:
    def totalMoney(self, n: int) -> int:
        div = n // 7
        rem = n % 7
        rep = max(0, div - 1)
        return int(28 * div + 7 * (rep * (rep + 1) / 2) + (rem * (2 * div + 1 + rem) / 2))