class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        res = ""
        for word in words:
            score = 0
            for ch in word:
                score += weights[ord(ch) - ord('a')]
            res += chr(ord('z') - (score % 26))
        return res