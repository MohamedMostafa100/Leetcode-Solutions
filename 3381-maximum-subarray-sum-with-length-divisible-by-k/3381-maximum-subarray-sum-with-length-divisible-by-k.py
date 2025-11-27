class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        res = float('-inf')
        pre = [0 for _ in range(len(nums))]
        l = 0
        sum = 0
        for r in range(len(nums)):
            sum += nums[r]
            if r - l + 1 < k:
                pre[r] = nums[r]
            else:
                pre[r] = sum
                sum -= nums[l]
                l += 1
        for i in range(k - 1, len(nums)):
            prev = 0
            if i - k >= k - 1:
                prev = pre[i - k] 
            res = max(res, pre[i] + prev)
            if pre[i] + prev < 0:
                pre[i] = 0
            else:
                pre[i] += prev
        return res