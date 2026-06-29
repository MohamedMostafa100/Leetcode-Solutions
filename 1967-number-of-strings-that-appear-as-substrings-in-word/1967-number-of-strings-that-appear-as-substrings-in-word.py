class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        res = 0
        for pat in patterns:
            if pat in word:
                res += 1
        return res