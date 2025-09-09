class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        res = 0
        mod = 1000000007
        tellDays = [0 for i in range(n + 1)]
        toAdd = [0 for i in range(n + 1)]
        toAdd[1] = 1
        tellDays[1] = 1
        for i in range(1, n + 1):
            if tellDays[i] != 0:
                for j in range(i + delay, min(n + 1, i + forget)):
                    toAdd[j] += tellDays[i] % mod
                    tellDays[j] = (tellDays[j] + tellDays[i]) % mod
                if i + forget <= n:
                    toAdd[i + forget] -= tellDays[i]
            res = (res + toAdd[i]) % mod
        return (res + mod) % mod