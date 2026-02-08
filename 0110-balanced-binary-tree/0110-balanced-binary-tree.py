# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def height(root) -> int:
            if not root:
                return 0
            l = height(root.left)
            if l == float('inf'):
                return float('inf')
            r = height(root.right)
            if abs(l - r) > 1:
                return float('inf')
            return max(l, r) + 1
        if height(root) == float('inf'):
            return False
        return True
