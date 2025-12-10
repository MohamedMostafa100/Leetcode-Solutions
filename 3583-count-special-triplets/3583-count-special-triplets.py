class Solution:
    def specialTriplets(self, nums: List[int]) -> int:
        res = 0
        MOD = 1000000007
        freqs = Counter(nums)
        leftFreqs = {}
        for num in nums:
            leftCount = leftFreqs[num * 2] if num * 2 in leftFreqs else 0
            leftFreqs[num] = leftFreqs.get(num, 0) + 1
            rightCount = freqs[num * 2] - leftCount if num > 0 else freqs[0] - leftFreqs[0]
            res = (res + ((rightCount * leftCount) % MOD)) % MOD;
        return res