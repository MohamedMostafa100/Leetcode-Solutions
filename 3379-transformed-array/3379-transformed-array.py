class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        result = []
        for i, num in enumerate(nums):
            if num == 0:
                result.append(num)
            else:
                result.append(nums[(i + (num // abs(num)) * (abs(num) % len(nums)) + len(nums)) % len(nums)])
        return result