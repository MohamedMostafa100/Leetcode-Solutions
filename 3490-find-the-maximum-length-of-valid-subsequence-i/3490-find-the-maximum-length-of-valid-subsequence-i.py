class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        prev = nums[0]
        alternating = 1
        even = 0
        odd = 0
        for num in nums:
            if num % 2 != prev % 2:
                alternating += 1
                prev = num
            if num % 2 == 0:
                even += 1
            else:
                odd += 1

        return max(alternating, even, odd)


        