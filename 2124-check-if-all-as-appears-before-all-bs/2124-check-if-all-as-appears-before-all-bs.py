class Solution:
    def checkString(self, s: str) -> bool:
        return True if re.fullmatch(r"a*b*", s) else False