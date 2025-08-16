class Solution:
    def largestGoodInteger(self, num: str) -> str:
        largestNum = 0
        goodIdx = -1
        for i in range(len(num) - 2):
            if (
                num[i] == num[i + 1]
                and num[i + 1] == num[i + 2]
                and num[i] == num[i + 2]
            ):
                if ord(num[i]) - ord("0") > largestNum or goodIdx == -1:
                    goodIdx = i
                    largestNum = ord(num[i]) - ord("0")
        return num[goodIdx : goodIdx + 3]
