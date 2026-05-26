class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        res = 0
        found = set()
        for ch in word:
            if ch not in found:
                if ch.islower():
                    if ch.upper() in found:
                        res += 1
                else:
                    if ch.lower() in found:
                        res += 1
                found.add(ch)
        return res