class Solution:
    def earliestFinishTime(self, landStartTime: List[int], landDuration: List[int], waterStartTime: List[int], waterDuration: List[int]) -> int:
        res = float('inf')
        landMin = float('inf')
        waterMin = float('inf')
        for i in range(len(landStartTime)):
            landMin = min(landMin, landStartTime[i] + landDuration[i])
        for i in range(len(waterStartTime)):
            res = min(res, max(landMin, waterStartTime[i]) + waterDuration[i])
        for i in range(len(waterStartTime)):
            waterMin = min(waterMin, waterStartTime[i] + waterDuration[i])
        for i in range(len(landStartTime)):
            res = min(res, max(waterMin, landStartTime[i]) + landDuration[i])
        return res;