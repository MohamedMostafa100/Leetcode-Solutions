class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        res = []
        idxPre = {}
        idxSuf = {}
        pre = [0 for _ in range(len(nums))]
        suf = [0 for _ in range(len(nums))]
        for i in range(len(nums)):
            if nums[i] in idxPre:
                pre[i] = pre[idxPre[nums[i]][0]] + ((i - idxPre[nums[i]][0]) * idxPre[nums[i]][1])
                idxPre[nums[i]] = (i, idxPre[nums[i]][1] + 1)
            else:
                idxPre[nums[i]] = (i, 1)
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] in idxSuf:
                suf[i] = suf[idxSuf[nums[i]][0]] + ((idxSuf[nums[i]][0] - i) * idxSuf[nums[i]][1])
                idxSuf[nums[i]] = (i, idxSuf[nums[i]][1] + 1)
            else:
                idxSuf[nums[i]] = (i, 1)
        for i  in range(len(nums)):
            res.append(pre[i] + suf[i])
        return res
        