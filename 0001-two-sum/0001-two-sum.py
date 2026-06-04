class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        found = {}
        for i, num in enumerate(nums):
            if (target - num) in found:
                return [found[target - num], i]
            found[num] = i