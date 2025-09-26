class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        res = 0
        nums = sorted(nums)
        for s1 in range(len(nums) - 2):
            if nums[s1] == 0:
                continue
            s3 = s1 + 2
            print(s3)
            for s2 in range(s1 + 1, len(nums) - 1):
                while s3 < len(nums) and nums[s3] < nums[s1] + nums[s2]:
                    s3 += 1
                res += s3 - s2 - 1
        return res