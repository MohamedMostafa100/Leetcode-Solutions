class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = ""
        base2 = set()
        for num in nums:
            base2.add(int(num, 2))
        for i in range(1 << len(nums[0])):
            if i not in base2:
                res = bin(i)[2:]
                while(len(res) < len(nums[0])):
                    res = '0' + res
                break
        return res