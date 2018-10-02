#! python3
# -*- coding: utf-8 -*-


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def getMinimumDifference(self, root):
        """
            :type root: TreeNode
            :rtype: int
            利用二叉查找树中序遍历是有序的性质去解决问题
        """
        def inorder(root):
            if root is None:
                return
            inorder(root.left)
            if self.prev is not None:
                min(self.min_diff, root.val - self.prev)
            self.prev = root.val
            inorder(root.right)

        self.min_diff = float('inf')
        self.prev = None
        inorder(root)

        return self.min_diff
