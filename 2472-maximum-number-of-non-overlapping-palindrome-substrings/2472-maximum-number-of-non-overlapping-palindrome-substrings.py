class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        res = 0
        start = 0
        def check(l: int, r: int) -> bool:
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True
        for r in range(k - 1, len(s)):
            if (r - k + 1 >= start and check(r - k + 1, r)) or (r - k >= start and check(r - k, r)):
                res += 1
                start = r + 1
        return res
        