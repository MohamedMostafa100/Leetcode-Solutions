class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = 1
        nums = [(num, i) for i, num in enumerate(arr)]
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i][0] > nums[i - 1][0]:
                rank += 1
            arr[nums[i][1]] = rank
        return arr