class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        res = 0
        nums = []
        last = grid[0][0]
        for row in grid:
            for cell in row:
                if abs(cell - last) % x != 0:
                    return -1
                nums.append(cell)
                last = cell
        nums.sort()
        mid = nums[len(nums) // 2]
        for num in nums:
            res += abs(num - mid) // x
        return res