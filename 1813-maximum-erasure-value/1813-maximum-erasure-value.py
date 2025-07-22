class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        res = 0
        inSubarr = set()
        l = 0
        sum = 0
        for num in nums:
            while num in inSubarr:
                sum -= nums[l]
                inSubarr.remove(nums[l])
                l += 1
            inSubarr.add(num)
            sum += num
            res = max(res, sum)
        return res
