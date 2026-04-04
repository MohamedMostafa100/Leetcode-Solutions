class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        res = ""
        cols = len(encodedText) // rows
        if cols == 0:
            return ""
        textMat = [list(encodedText[i * cols : i * cols + cols]) for i in range(rows)]
        for idx in range(cols):
            i = 0
            j = idx
            while i < rows and j < cols:
                res += textMat[i][j]
                i += 1
                j += 1
        return res.rstrip()