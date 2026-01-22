class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        res = 0
        def checkSorted() -> bool:
            for i in range(1, len(nums)):
                if nums[i] < nums[i - 1]:
                    return False
            return True
        while not checkSorted():
            minSum = float('inf')
            minIndex = -1
            for i in range(len(nums) - 1):
                if nums[i] + nums[i + 1] < minSum:
                    minSum = nums[i] + nums[i + 1]
                    minIndex = i
            nums[minIndex] += nums[minIndex + 1]
            nums.pop(minIndex + 1)
            res += 1
        return res
