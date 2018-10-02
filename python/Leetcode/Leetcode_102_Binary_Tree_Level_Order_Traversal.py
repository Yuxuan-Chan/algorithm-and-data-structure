#! python3
# -*- coding: utf-8 -*-


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    """
    利用bfs
    """
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = []
        if root is None:
            return res

        queue = [root]
        while len(queue) > 0:
            res.append([node.val for node in queue])
            new_queue = []  # 在不断的赋值中，最后会赋给空的列表给queue,所以必然会退出循环
            for node in queue:
                if node.left is not None:
                    new_queue.append(node.left)
                if node.right is not None:
                    new_queue.append(node.right)
            print(queue)
            queue = new_queue
        return res


class Solution0:
    """
    利用dfs
    """
    def dfs(self, root, depth, res):
        if root is None:
            return res

        if len(res) < depth+1:
            res.append([])
        res[depth].append(root.val)
        self.dfs(root.left, depth+1, res)
        self.dfs(root.right, depth+1, res)

    def levelOrder(self, root):
        res = []
        self.dfs(root, 0, res)
        return res
