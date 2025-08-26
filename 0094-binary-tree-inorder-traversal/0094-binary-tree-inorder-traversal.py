# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        res = []
        stk = []
        stk.append(root)
        while len(stk) > 0:
            p = stk[-1]
            while p.left:
                stk.append(p.left)
                p = p.left
            while len(stk) > 0:
                p = stk[-1]
                res.append(p.val)
                stk.pop()
                if p.right:
                    stk.append(p.right)
                    break
        return res