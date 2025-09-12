class Solution:
    def doesAliceWin(self, s: str) -> bool:
        vowels = 0
        for char in s:
            if char == 'a' or char == 'e' or char == 'i' or char == 'o' or char == 'u':
                vowels += 1
        if vowels > 0:
            return True
        return False