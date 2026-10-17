class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        res = 0
        idxs = {nums[i] : i for i in range(len(nums))}
        def sumDigits(x: int) -> int:
            res = 0
            while x > 0:
                res += x % 10
                x //= 10
            return res
        sortedNums = sorted(nums, key= lambda x: (sumDigits(x), x))
        for i in range(len(nums)):
            if nums[i] != sortedNums[i]:
                res += 1
                temp = nums[i]
                nums[i], nums[idxs[sortedNums[i]]] = nums[idxs[sortedNums[i]]], nums[i]
                idxs[temp] = idxs[sortedNums[i]]
        return res
        

        