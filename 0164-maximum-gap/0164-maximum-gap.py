class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        res = 0
        n = len(nums)
        minVal = float('inf')
        maxVal = 0
        for num in nums:
            minVal = min(minVal, num)
            maxVal = max(maxVal, num)
        bucketSize = max(1, (maxVal - minVal) // (n - 1))
        bucketCount = (maxVal - minVal) // bucketSize + 1
        buckets = [(float('inf'), 0 ) for _ in range(bucketCount)]
        for num in nums:
            idx = (num - minVal) // bucketSize
            idxMin, idxMax = buckets[idx]
            buckets[idx] = (min(idxMin, num), max(idxMax, num))
        last = buckets[0][1]
        for i in range(1, bucketCount):
            if buckets[i][0] == float('inf'):
                continue
            res = max(res, buckets[i][0] - last)
            last = buckets[i][1]
        return res
