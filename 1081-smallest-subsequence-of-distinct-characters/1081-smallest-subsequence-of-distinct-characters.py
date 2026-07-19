class Solution:
    def smallestSubsequence(self, s: str) -> str:
        res = []
        alpha = [0 for _ in range(26)]
        for ch in s:
            alpha[ord(ch) - ord('a')] += 1
        for ch in s:
            alpha[ord(ch) - ord('a')] -= 1
            if ch in res:
                continue
            while len(res) > 0 and ord(ch) < ord(res[-1]) and alpha[ord(res[-1]) - ord('a')] > 0:
                res.pop()
            res.append(ch)
        return "".join(res)