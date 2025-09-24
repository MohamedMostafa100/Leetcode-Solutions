class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return '0'
        res = '-' if (numerator < 0) ^ (denominator < 0) else ''
        numerator = abs(numerator)
        denominator = abs(denominator)
        fraction = ''
        remPos = {}
        pos = 0
        res += str(numerator // denominator)
        numerator %= denominator
        numerator *= 10
        while numerator > 0:
            cur = numerator // denominator
            rem = numerator % denominator
            print(denominator)
            if cur in remPos:
                if rem in remPos[cur]:
                    fraction = f"{fraction[0:remPos[cur][rem]]}({fraction[remPos[cur][rem]:]})"
                    break
            fraction += str(cur)
            if cur not in remPos:
                remPos[cur] = {}
            remPos[cur][rem] = pos
            pos += 1
            numerator = rem
            numerator *= 10
        if len(fraction) > 0:
            res += f".{fraction}"
        return res

        
        
