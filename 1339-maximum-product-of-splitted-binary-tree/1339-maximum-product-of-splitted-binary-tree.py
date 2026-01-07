# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def calcSum(root: Optional[TreeNode]) -> int:
    if not root:
        return 0
    tot = root.val
    tot += calcSum(root.left)
    tot += calcSum(root.right)
    return tot
class Solution:
    def solve(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        subTreeSum = root.val
        subTreeSum += self.solve(root.left)
        subTreeSum += self.solve(root.right)
        self.res = max(self.res, subTreeSum * (self.tot - subTreeSum))
        return subTreeSum
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        self.res = 0
        self.tot = calcSum(root)
        self.solve(root)
        return self.res % 1000000007
        
        