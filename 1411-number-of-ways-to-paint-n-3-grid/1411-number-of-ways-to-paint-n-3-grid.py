class Solution:
    def numOfWays(self, n: int) -> int:
        abc = 6
        aba = 6
        for _ in range(n - 1):
            temp1 = (abc * 2 + aba * 2) % 1000000007
            temp2 = (abc * 2 + aba * 3) % 1000000007
            abc = temp1
            aba = temp2
        return (abc + aba) % 1000000007