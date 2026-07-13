class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        for i in range(1, 10):
            cur = i 
            curNum = cur
            while curNum <= high and cur <= 9:
                if curNum >= low:
                    res.append(curNum)
                cur += 1
                curNum = curNum * 10 + cur
        res.sort()
        return res