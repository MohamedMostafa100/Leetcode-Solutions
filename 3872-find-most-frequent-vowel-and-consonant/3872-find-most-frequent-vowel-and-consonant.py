class Solution:
    def maxFreqSum(self, s: str) -> int:
        maxVowel = 0
        maxConst = 0
        alpha = [0 for i in range(26)]
        for ch in s:
            alpha[ord(ch) - ord('a')] += 1
            if ch in {'a','e','i','o','u'}:
                maxVowel = max(maxVowel, alpha[ord(ch) - ord('a')])
            else:
                maxConst = max(maxConst, alpha[ord(ch) - ord('a')])
        return maxVowel + maxConst