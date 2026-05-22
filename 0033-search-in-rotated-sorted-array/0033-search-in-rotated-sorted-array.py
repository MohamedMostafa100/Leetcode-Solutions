class Solution:
    def search(self, nums: List[int], target: int) -> int:
        res = -1
        l = 0
        r = len(nums)
        while l < r:
            mid = (l + r) // 2
            if target < nums[mid]:
                if nums[l] > nums[mid] or target >= nums[l]:
                    r = mid
                else:
                    l = mid + 1
            elif target > nums[mid]:
                if nums[r - 1] < nums[mid] or target <= nums[r - 1]:
                    l = mid + 1
                else:
                    r = mid
            else:
                res = mid
                break
        return res