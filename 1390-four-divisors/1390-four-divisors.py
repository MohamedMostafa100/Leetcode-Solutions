class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        res = 0
        for num in nums:
            tot = num + 1
            size = 2
            for i in range(2, int(sqrt(num) + 1)):
                if num % i == 0:
                    tot += i + (num // i)
                    if i == (num // i):
                        size += 1
                    else:
                        size += 2
            if size == 4:
                res += tot
        return res