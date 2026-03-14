class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        def nextChar(cur: str, idx: int) -> str:
            if cur == '':
                if idx == 0:
                    return 'a'
                elif idx == 1:
                    return 'b'
                return 'c'
            elif cur == 'a':
                if idx == 0:
                    return 'b'
                return 'c'
            elif cur == 'b':
                if idx == 0:
                    return 'a'
                return 'c'
            else:
                if idx == 0:
                    return 'a'
                return 'b'
            return ''
        if k > 3 * (1 << (n - 1)):
            return ''
        res = ""
        last = ''
        k -= 1
        while n > 0:
            idx = k // (1 << (n - 1))
            last = nextChar(last, idx)
            res += last
            k %= (1 << (n - 1))
            n -= 1
        return res