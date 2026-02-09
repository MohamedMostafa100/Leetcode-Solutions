# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        nums = []
        def inOrder(root: Optional[TreeNode]) -> None:
            if not root:
                return
            inOrder(root.left)
            nums.append(root.val)
            inOrder(root.right)
        inOrder(root)
        def constructTree(i: int, j: int) -> Optional[TreeNode]:
            if i == j:
                return None
            mid = (i + j) // 2
            newRoot = TreeNode(nums[mid])
            newRoot.left = constructTree(i, mid)
            newRoot.right = constructTree(mid + 1, j)
            return newRoot
        return constructTree(0, len(nums))
        
