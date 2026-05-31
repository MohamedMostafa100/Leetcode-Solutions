class Solution:
    def countPrimes(self, n: int) -> int:
        if n == 0 or n == 1:
            return 0
        sieve = [True for _ in range(n)]
        sieve[0] = False
        sieve[1] = False
        for i in range(2, int(sqrt(n)) + 1):
            if sieve[i]:
                for j in range(i + i, n, i):
                    sieve[j] = False
        return sieve.count(True)
