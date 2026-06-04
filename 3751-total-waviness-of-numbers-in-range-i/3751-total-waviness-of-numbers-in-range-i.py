class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        res = 0
        for i in range(num1, num2 + 1):
            strInt = str(i)
            for j in range(1, len(strInt) - 1):
                if (int(strInt[j]) > int(strInt[j - 1]) and int(strInt[j]) > int(strInt[j + 1])) or (int(strInt[j]) < int(strInt[j - 1]) and int(strInt[j]) < int(strInt[j + 1])):
                    res += 1
        return res