#! python3
# -*- coding: utf-8 -*-


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


"""
前序遍历: 根节点->左子树->右子树
中序遍历: 左子树->根节点->右子树 中序遍历的结果是有序的
后序遍历: 左子树->右子树->根节点
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def build_no_left_tree(self, in_order_res):
        res = []
        for index, value in enumerate(in_order_res):
            if index == 0:
                res.append(value)
            else:
                res.append(None)
                res.append(value)
        return res

    def helper(self, root, res):
        if root is not None:
            if root.left is not None:
                self.helper(root.left, res)
            res.append(root.val)
            if root.right is not None:
                self.helper(root.right, res)

    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        res = []
        self.helper(root, res)
        return self.build_no_left_tree(res)



