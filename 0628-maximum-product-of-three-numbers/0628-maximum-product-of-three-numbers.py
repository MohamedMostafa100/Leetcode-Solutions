import numpy as np

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        top = []
        bottom = []
        mx = -1000
        for num in nums:
            mx = max(mx, num)
            if len(top) < 3:
                top.append(num)
            else:
                minI = np.argmin(top)
                if num > top[minI]:
                    top[minI] = num
            if len(bottom) < 2:
                bottom.append(num)
            else:
                maxI = np.argmax(bottom)
                if num < bottom[maxI]:
                    bottom[maxI] = num
        return max(top[0] * top[1] * top[2], bottom[0] * bottom[1] * mx)
