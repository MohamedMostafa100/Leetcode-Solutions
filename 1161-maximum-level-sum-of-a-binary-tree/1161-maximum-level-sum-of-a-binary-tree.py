# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def traverse(root: Optional[TreeNode], lvlSum: dict[int, int], lvl: int) -> None:
    if root == None:
        return
    if lvl not in lvlSum:
        lvlSum[lvl] = 0
    lvlSum[lvl] += root.val
    traverse(root.left, lvlSum, lvl + 1)
    traverse(root.right, lvlSum, lvl + 1)
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        res = -1
        maxVal = float('-inf')
        lvlSum = {}
        traverse(root, lvlSum, 1)
        for lvl, val in lvlSum.items():
            if val > maxVal:
                res = lvl
                maxVal = val
            elif val == maxVal:
                res = min(res, lvl)
        return res
        