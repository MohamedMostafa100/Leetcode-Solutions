# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        res = 0
        def solve(root: Optional[TreeNode], tot: int) -> None:
            nonlocal res
            if not root:
                return
            if (not root.left) and (not root.right):
                res += (tot * 2 + root.val)
                return
            solve(root.left, tot * 2 + root.val)
            solve(root.right, tot * 2 + root.val)
        solve(root, 0)
        return res
            