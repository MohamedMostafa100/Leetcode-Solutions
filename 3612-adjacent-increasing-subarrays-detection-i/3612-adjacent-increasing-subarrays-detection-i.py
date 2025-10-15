class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        if k == 1:
            return True
        incSubs = set()
        l = 0
        for r in range(1, len(nums)):
            if nums[r] > nums[r - 1]:
                if r - l + 1 == k:
                    if l - k in incSubs:
                        return True
                    incSubs.add(l)
                    l += 1
            else:
                l = r
        return False