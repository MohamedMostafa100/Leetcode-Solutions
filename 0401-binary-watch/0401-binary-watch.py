def countBits(n: int) -> int:
    bits = 0
    mask = 1
    for i in range(10):
        if mask & n:
            bits += 1
        mask <<= 1
    return bits
class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        ans = []
        hoursMask = 960
        minsMask = 63
        for i in range(1, 1025):
            if countBits(i) == turnedOn:
                h = (hoursMask & i) >> 6
                m = minsMask & i
                if h > 11 or m > 59:
                    continue
                ans.append(f"{h}:{m}") if m >= 10 else ans.append(f"{h}:0{m}")
        return ans
        