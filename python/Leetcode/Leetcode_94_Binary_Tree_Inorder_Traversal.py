#! python3
# -*- coding: utf-8 -*-


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    """
    经典解法，利用递归解决
    """
    def helper(self, root, res):
        if root is not None:
            if root.left is not None:
                self.helper(root.left, res)
            res.append(root.val)
            if root.right is not None:
                self.helper(root.right, res)

    def inorderTraversal(self, root):
        """
        中序遍历
        :param root:
        :return:
        """
        res = []
        self.helper(root, res)
        return res


class Solution0:
    """
    利用堆栈
    """
    def inorderTraversal(self, root):
        res = []
        stack = []
        curr = root
        while curr is not None or len(stack) > 0:
            while curr is not None:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            res.append(curr.val)
            curr = curr.right
        return res
