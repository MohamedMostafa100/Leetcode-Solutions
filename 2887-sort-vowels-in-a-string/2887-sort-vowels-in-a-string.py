class Solution:
    def sortVowels(self, s: str) -> str:
        t = ''
        sortedVowels = 'AEIOUaeiou'
        vowels = {'A': 0, 'E': 0, 'I': 0, 'O': 0, 'U': 0, 'a': 0, 'e': 0, 'i': 0, 'o': 0, 'u': 0}
        for char in s:
            if char in vowels:
                vowels[char] += 1
        for char in s:
            if char in vowels:
                for vowel in sortedVowels:
                    if vowels[vowel] > 0:
                        t += vowel
                        vowels[vowel] -= 1
                        break
                continue
            t += char
        return t