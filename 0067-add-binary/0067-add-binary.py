class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        while i >= 0 or j >= 0:
            x = 0
            y = 0
            if i >= 0:
                x = int(a[i])
                i -= 1
            if j >= 0:
                y = int(b[j])
                j -= 1
            res = str(x ^ y ^ carry) + res
            carry = (x + y + carry) // 2
        if carry == 1:
            res = '1' + res
        return res