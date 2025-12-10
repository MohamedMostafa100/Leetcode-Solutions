class Solution:
    def fact(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        return (n * self.fact(n - 1)) % 1000000007
    def countPermutations(self, complexity: List[int]) -> int:
        for c in complexity[1:]:
            if c <= complexity[0]:
                return 0
        return self.fact(len(complexity) - 1)
        