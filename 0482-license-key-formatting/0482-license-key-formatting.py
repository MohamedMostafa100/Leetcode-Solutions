class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        res = ""
        count = 0
        for ch in s[::-1]:
            if ch != '-':
                res = ch.upper() + res
                count += 1
                if count == k:
                    res = '-' + res
                    count = 0
        return res if (len(res) == 0 or res[0] != '-' ) else res[1:]
