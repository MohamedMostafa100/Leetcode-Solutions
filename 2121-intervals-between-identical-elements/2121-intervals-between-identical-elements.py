class Solution:
    def getDistances(self, arr: List[int]) -> List[int]:
        res = []
        idxPre = {}
        idxSuf = {}
        pre = [0 for _ in range(len(arr))]
        suf = [0 for _ in range(len(arr))]
        for i in range(len(arr)):
            if arr[i] in idxPre:
                pre[i] = pre[idxPre[arr[i]][0]] + ((i - idxPre[arr[i]][0]) * idxPre[arr[i]][1])
                idxPre[arr[i]] = (i, idxPre[arr[i]][1] + 1)
            else:
                idxPre[arr[i]] = (i, 1)
        for i in range(len(arr) - 1, -1, -1):
            if arr[i] in idxSuf:
                suf[i] = suf[idxSuf[arr[i]][0]] + ((idxSuf[arr[i]][0] - i) * idxSuf[arr[i]][1])
                idxSuf[arr[i]] = (i, idxSuf[arr[i]][1] + 1)
            else:
                idxSuf[arr[i]] = (i, 1)
        for i  in range(len(arr)):
            res.append(pre[i] + suf[i])
        return res