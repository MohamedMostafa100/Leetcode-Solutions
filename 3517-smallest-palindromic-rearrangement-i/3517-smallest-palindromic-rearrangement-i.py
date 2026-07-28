class Solution:
    def smallestPalindrome(self, s: str) -> str:
        n = len(s)
        res = ['a' for _ in range(n)]
        alpha = [0 for _ in range(26)]
        i = 0
        for ch in s:
            alpha[ord(ch) - ord('a')] += 1
        for idx in range(26):
            freq = alpha[idx]
            if freq == 1:
                res[n // 2] = chr(idx + ord('a'))
            elif freq >= 2:
                for j in range(freq // 2):
                    res[i] = chr(idx + ord('a'))
                    res[-i - 1] = chr(idx + ord('a'))
                    freq -= 2
                    i += 1
                if freq == 1:
                    res[n // 2] = chr(idx + ord('a'))
        return "".join(res)