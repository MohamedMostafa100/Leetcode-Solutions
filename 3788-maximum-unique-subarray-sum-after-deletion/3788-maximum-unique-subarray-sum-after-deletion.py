class Solution:
    def maxSum(self, nums: List[int]) -> int:
        inArr = set()
        res = -1
        sum = 0
        maxNeg = float("-inf")
        for num in nums:
            if num >= 0 and num not in inArr:
                sum += num
                res = max(res, sum)
                inArr.add(num)
            else:
                maxNeg = max(maxNeg, num)
        if res == -1:
            return maxNeg
        else:
            return res
        