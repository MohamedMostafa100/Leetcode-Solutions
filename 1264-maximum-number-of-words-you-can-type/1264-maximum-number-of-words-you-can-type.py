class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        res = 0
        broken = set(brokenLetters)
        wordList = text.split(' ')
        for word in wordList:
            for ch in word:
                if ch in broken:
                    res -= 1
                    break
            res += 1
        return res
            