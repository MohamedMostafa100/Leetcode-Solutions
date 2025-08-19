class Solution:
    def solve(self, nums: List[float]) -> bool:
        if len(nums) == 1:
            return abs(nums[0] - 24) < 1e-6
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i == j:
                    continue
                nxt = [nums[k] for k in range(len(nums)) if k != i and k != j]
                a = nums[i]
                b = nums[j]
                ops = [a + b, a - b, b - a, a * b]
                if abs(b) > 1e-6:
                    ops.append(a / b)
                if abs(a) > 1e-6:
                    ops.append(b / a)
                for op in ops:
                    nxt.append(op)
                    if self.solve(nxt):
                        return True
                    nxt.pop()
        return False
    def judgePoint24(self, cards: List[int]) -> bool:
        nums = [card for card in cards]
        return self.solve(nums)
        