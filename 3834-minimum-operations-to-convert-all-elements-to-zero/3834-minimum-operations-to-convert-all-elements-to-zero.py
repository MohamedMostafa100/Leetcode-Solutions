class Solution:
    def minOperations(self, nums: List[int]) -> int:
        res = 0
        stk = []
        for num in nums:
            while len(stk) > 0 and num < stk[-1]:
                stk.pop()
            if (len(stk) == 0 or num > stk[-1]) and num > 0:
                stk.append(num)
                res += 1
        return res

                    