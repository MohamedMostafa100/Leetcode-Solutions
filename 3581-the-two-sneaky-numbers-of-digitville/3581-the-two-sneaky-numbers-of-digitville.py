class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        res = []
        exist = [False for _ in range(len(nums))]
        for num in nums:
            if exist[num]:
                res.append(num)
            else:
                exist[num] = True
        return res