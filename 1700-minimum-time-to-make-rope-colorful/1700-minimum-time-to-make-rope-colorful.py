class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        res = 0
        sum = neededTime[0]
        maxNum = sum
        for i in range(1, len(colors)):
            if colors[i] == colors[i - 1]:
                sum += neededTime[i]
                maxNum = max(maxNum, neededTime[i])
            else:
                res += sum - maxNum
                sum = neededTime[i]
                maxNum = sum
        res += sum - maxNum
        return res