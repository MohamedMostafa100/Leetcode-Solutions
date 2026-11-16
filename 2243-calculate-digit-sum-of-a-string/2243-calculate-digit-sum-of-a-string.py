class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            newS = ""
            tot = 0
            count = 0
            for c in s:
                tot += int(c)
                count += 1
                if count == k:
                    newS += f"{tot}"
                    tot = 0
                    count = 0
            if count > 0:
                newS += f"{tot}"
            s = newS
        return s