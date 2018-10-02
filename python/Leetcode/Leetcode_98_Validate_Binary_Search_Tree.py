#! python3
# -*- coding: utf-8 -*-


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    """
    利用中序遍历二叉树的特性，得到的序列一定是有序递增的
    """
    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        self.arr.append(root.val)
        self.inorder(root.right)

    def isValidBST(self, root):
        self.arr = []
        self.inorder(root)
        return sorted(self.arr) == self.arr and len(self.arr) == len(set(self.arr))


class Solution0:
    """
    对上面的方法进行改进，每次只需要将当前root.val和上次存储的self.last比对即可知道是否满足条件，然后设立self.flag用于返回
    """
    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        if self.lastVal >= root.val:
            self.flag = False
        self.lastVal = root.val
        self.inorder(root.right)

    def isValidBST(self, root):
        self.lastVal = -float('inf')
        self.flag = True
        self.inorder(root)
        return self.flag