class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        lastOne = -1
        for i, ch in enumerate(nums):
            if ch == 1:
                if lastOne == -1:
                    lastOne = i
                else:
                    if i - lastOne - 1 < k:
                        return False
                    else:
                        lastOne = i
        return True