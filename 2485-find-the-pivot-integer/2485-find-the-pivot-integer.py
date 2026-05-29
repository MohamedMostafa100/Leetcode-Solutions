class Solution:
    def pivotInteger(self, n: int) -> int:
        totSum = n * (n + 1) / 2
        curSum = 0
        for i in range(1, n + 1):
            curSum += i
            if curSum == totSum - curSum + i:
                return i
        return -1
