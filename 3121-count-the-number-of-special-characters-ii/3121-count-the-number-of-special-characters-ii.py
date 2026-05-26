class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        found = set()
        uniq = set()
        for ch in word:
            if ch.isupper():
                if ch.lower() in found and ch not in found:
                    uniq.add(ch)
            else:
                if ch in found and ch.upper() in found:
                    if ch.upper() in uniq:
                        uniq.remove(ch.upper())
            found.add(ch)
        return len(uniq)
