class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        for let in letters:
            if ord(let) > ord(target):
                return let
        return letters[0]