class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        maxFreq = 0
        repeated = 0
        freqs = {}
        for num in nums:
            if num not in freqs:
                freqs[num] = 0
            freqs[num] += 1
            if freqs[num] > maxFreq:
                maxFreq = freqs[num]
                repeated = 1
            elif freqs[num] == maxFreq:
                repeated += 1
        return maxFreq * repeated