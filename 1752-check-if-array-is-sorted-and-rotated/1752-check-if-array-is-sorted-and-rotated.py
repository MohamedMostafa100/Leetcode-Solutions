class Solution:
    def check(self, nums: List[int]) -> bool:
        turn = False
        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                if turn:
                    return False
                else:
                    turn = True
        if turn and nums[0] < nums[-1]:
            return False
        return True