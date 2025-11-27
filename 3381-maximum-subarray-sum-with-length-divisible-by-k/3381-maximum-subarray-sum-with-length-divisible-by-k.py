class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        res = float('-inf')
        pre = [0 for _ in range(len(nums))]
        l = 0
        sum = 0            
        for r in range(0, len(nums)):
            sum += nums[r]
            if r - l + 1 < k:
                pre[r] = nums[r]
            else:
                pre[r] = sum
                sum -= nums[l]
                l += 1
            if r >= k - 1:
                prev = 0
                if r - k >= k - 1:
                    prev = pre[r - k] 
                res = max(res, pre[r] + prev)
                if pre[r] + prev < 0:
                    pre[r] = 0
                else:
                    pre[r] += prev
            
        return res