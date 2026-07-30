class Solution:
    def minimumPushes(self, word: str) -> int:
        n = len(word)
        qtnt = n // 8
        rem = n % 8
        return 8 * qtnt * (qtnt + 1) // 2 + rem * (qtnt + 1) 