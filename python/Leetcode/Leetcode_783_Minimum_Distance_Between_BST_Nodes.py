#! python3
# -*- coding: utf-8 -*-


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def minDiffInBST(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        vals = []
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            vals.append(root.val)
            inorder(root.right)

        inorder(root)
        return min([vals[i+1] - vals[i] for i in range(len(vals) - 1)])