class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        res = []
        commCount = 0
        seen = [0 for _ in range(len(A))]
        for i in range(len(A)):
            seen[A[i] - 1] += 1
            if seen[A[i] - 1] == 2:
                commCount += 1
            seen[B[i] - 1] += 1
            if seen[B[i] - 1] == 2:
                commCount += 1
            res.append(commCount)
        return res