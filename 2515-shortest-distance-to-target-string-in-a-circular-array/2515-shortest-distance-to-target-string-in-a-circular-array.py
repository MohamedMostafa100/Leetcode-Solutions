class Solution:
    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        n = len(words)
        res = n
        for i in range(n):
            if words[i] == target:
                res = min(res, abs(i - startIndex), i + n - startIndex, startIndex + n - i)
        return -1 if res == n else res