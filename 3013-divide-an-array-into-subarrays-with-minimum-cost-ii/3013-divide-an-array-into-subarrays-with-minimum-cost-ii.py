class Solution:
    def minimumCost(self, nums: List[int], k: int, dist: int) -> int:
        res = float('inf')
        l = 2
        r = 2
        window = SortedList()
        smallest = SortedList([nums[l]])
        windowSum = nums[l]
        for i in range(1, len(nums) - k + 2):
            print(i)
            while r - l + 1 < min(dist, len(nums) - i - 1):
                r += 1
                print(r - l + 1)
                if len(smallest) < k - 2:
                    smallest.add(nums[r])
                    windowSum += nums[r]
                else:
                    if nums[r] < smallest[-1]:
                        windowSum += -smallest[-1] + nums[r]
                        window.add(smallest[-1])
                        smallest.pop()
                        smallest.add(nums[r])
                    else:
                        window.add(nums[r])
            res = min(res, nums[0] + nums[i] + windowSum)
            if nums[l] in smallest:
                smallest.remove(nums[l])
                windowSum -= nums[l]
                if len(window) > 0:
                    smallest.add(window[0])
                    windowSum += window[0]
                    window.pop(0)
            else:
                window.remove(nums[l])
            l += 1
        return res