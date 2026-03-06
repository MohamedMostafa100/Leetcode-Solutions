class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        finished = False
        for ch in s:
            if ch == '0' and not finished:
                finished = True
            elif ch == '1' and finished:
                return False
        return True