class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        sm = 0
        eq = 0
        for num in nums:
            if num < target:
                sm += 1
            elif num == target:
                eq += 1
        return [i for i in range(sm, sm + eq)]