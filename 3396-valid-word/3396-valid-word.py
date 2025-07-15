class Solution:
    def isValid(self, word: str) -> bool:
        if (len(word) < 3) or (not word.isalnum()):
            return False
        
        vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
        vowelCount = False
        conCount = False

        for char in word:
            if char in vowels:
                vowelCount = True
            elif not char.isdigit():
                conCount = True

        return vowelCount and conCount

        