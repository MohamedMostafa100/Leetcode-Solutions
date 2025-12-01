class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        s = set(friends)
        return [o for o in order if o in s]