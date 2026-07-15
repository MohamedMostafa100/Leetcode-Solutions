class Solution:
    def gcdOfOddEvenSums(self, n: int) -> int:
        # Sum of arthimetic series formula: n / 2 * [2 * a1 + (n - 1) * d]
        # n = number of terms
        # a1 = first term
        # d = common difference
        sumOdd = n + (n - 1) * n #a1 = 1, d = 2
        sumEven = 2 * n + (n - 1) * n #a1 = 2, d = 2
        return gcd(sumOdd, sumEven)