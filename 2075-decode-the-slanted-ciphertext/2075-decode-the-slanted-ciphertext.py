class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        res = ""
        cols = len(encodedText) // rows
        for idx in range(cols):
            i = 0
            j = idx
            while i < rows and j < cols:
                res += encodedText[i * cols + j]
                i += 1
                j += 1
        return res.rstrip()