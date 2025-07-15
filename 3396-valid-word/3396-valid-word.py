class Solution:
    def isValid(self, word: str) -> bool:
        if (len(word) < 3) or (not word.isalnum()):
            return False
        
        vowelCount = False
        conCount = False

        for char in word:
            if char.lower() in {'a', 'e', 'i', 'o', 'u'}:
                vowelCount = True
            elif not char.isdigit():
                conCount = True

        return vowelCount and conCount

        