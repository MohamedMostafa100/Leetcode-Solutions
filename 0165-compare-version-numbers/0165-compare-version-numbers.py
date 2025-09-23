class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1 = version1.split('.')
        v2 = version2.split('.')
        for num1, num2 in itertools.zip_longest(v1, v2, fillvalue='0'):
            if int(num1) > int(num2):
                return 1
            elif int(num1) < int(num2):
                return -1
        return 0