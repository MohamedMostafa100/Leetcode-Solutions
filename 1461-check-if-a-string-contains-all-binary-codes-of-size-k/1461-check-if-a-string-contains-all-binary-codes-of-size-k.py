class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        verified = set()
        for i in range(len(s) - k + 1):
            verified.add(s[i : i + k])
        if len(verified) == (1 << k):
            return True
        return False