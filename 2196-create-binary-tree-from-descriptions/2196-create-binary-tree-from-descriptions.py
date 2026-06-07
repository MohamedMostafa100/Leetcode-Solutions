# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        root = None
        nodes = {}
        for p, c, isLeft in descriptions:
            if p in nodes:
                parent = nodes[p][0]
            else:
                parent = TreeNode(p)
                nodes[p] = (parent, False)
            if c in nodes:
                child = nodes[c][0]
                nodes[c] = (child, True)
            else:
                child = TreeNode(c)
                nodes[c] = (child, True)
            if isLeft:
                parent.left = child
            else:
                parent.right = child
        for node, hasParent in nodes.values():
            if not hasParent:
                root = node
                break
        return root