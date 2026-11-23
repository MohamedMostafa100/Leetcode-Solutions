class ProductOfNumbers:

    def __init__(self):
        self.nums = [1]
        self.length = 0
        self.lastZero = float('-inf')

    def add(self, num: int) -> None:
        if num > 0:
            self.nums.append(num * self.nums[-1])
        else:
            self.lastZero = self.length
        self.length += 1

    def getProduct(self, k: int) -> int:
        return 0 if self.length - k <= self.lastZero else self.nums[-1] // self.nums[-k - 1]


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)