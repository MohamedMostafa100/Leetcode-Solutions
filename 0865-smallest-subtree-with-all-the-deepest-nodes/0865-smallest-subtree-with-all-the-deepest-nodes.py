# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def solve(self, root: Optional[TreeNode], lvl: int) -> int:
        if not root:
            return 0
        left = self.solve(root.left, lvl + 1)
        right = self.solve(root.right, lvl + 1)
        if right == left:
            if left + lvl >= self.depth:
                self.res = root
                self.depth = left + lvl
        return max(left, right) + 1
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.res = None
        self.depth = -1
        self.solve(root, 0)
        return self.res
        