class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        res = 0
        violation = False
        sortedIdxs = [False for _ in range(len(strs) - 1)]
        unSorted = len(strs) - 1
        i = 0
        while i < len(strs[0]) and unSorted > 0:
            violation = False
            for j in range(1, len(strs)):
                if not sortedIdxs[j - 1] and ord(strs[j][i]) < ord(strs[j - 1][i]):
                    res += 1
                    violation = True
                    break
            if not violation:
                for j in range(1, len(strs)):
                    if not sortedIdxs[j - 1] and ord(strs[j][i]) > ord(strs[j - 1][i]):
                        sortedIdxs[j - 1] = True
                        unSorted -= 1
            i += 1
        return res
