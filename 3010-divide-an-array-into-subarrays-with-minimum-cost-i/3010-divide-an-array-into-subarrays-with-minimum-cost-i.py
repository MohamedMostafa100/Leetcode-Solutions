class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        res = nums[0]
        mins = []
        for num in nums[1:]:
            if len(mins) < 2:
                mins.append(num) 
            else:
                if num < mins[1]:
                    mins[1] = num
            mins = sorted(mins)
        return res + sum(mins)