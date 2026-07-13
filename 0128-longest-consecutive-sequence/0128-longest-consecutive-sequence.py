class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        numSet = set(nums)
        visited = set()
        for n in numSet:
            if n not in visited:
                visited.add(n)
                cur = n + 1
                count = 1
                while cur in numSet:
                    count += 1
                    visited.add(cur)
                    cur += 1
                cur = n - 1
                while cur in numSet:
                    count += 1
                    visited.add(cur)
                    cur -= 1
                res = max(res, count)
        return res