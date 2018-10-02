#! python3
# -*- coding: utf-8 -*-


class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

# Clone an undirected graph, Each node in the graph contains a label and a list of its neighbors
# 克隆无向图，每一个在图中的结点都包含一个标签和一个邻接点的列表
# 关于无向图和有向图的区别
# 若边(u, v)所对应顶点u和v的次序无所谓，则称为无向边(undirected edge), 例如表示同学关系的边，反之若u和v不对等，则称(u, v)不对等
# 则称(u, v)为有向边，例如描述企业和银行之间的借贷关系，或者程序之间的相互调用关系的边
# 因此，无向边(u, v)也可记作(v, u), 而有向的(u, v)和(v, u)则不可混淆
# 所以可以分为基本的三种图，无向图，混合图，有向图


class Solution:
    def cloneGraph(self, node):
        def dfs(input, map):  # node {}, node: node.label  <=> input (相当于 node) : output (相当于 input.neighbors)
            if input in map:
                return map[input]
            output = UndirectedGraphNode(input.label)
            map[input] = output
            for neighbor in input.neighbors:
                output.neighbors.append(dfs(neighbor, map))  # 深度优先，优先选取最后一个被访问到的顶点的邻居，根据这一原则
                # 每遍历到一个结点，用递归去调用它的子结点
            return output
        if node is None:
            return None
        else:
            return dfs(node, {})


class Solution0:
    """
    利用bfs
    """
    def cloneGraph(self, node):
        if node is None:
            return None
        queue = []
        hashmap = {}
        new_head = UndirectedGraphNode(node.label)
        queue.append(node)
        hashmap[node] = new_head
        while queue:
            curr = queue.pop()
            for neighbor in curr.neighbors:
                if neighbor in hashmap:
                    hashmap[curr].neighbors.append(hashmap[neighbor])
                else:
                    copy = UndirectedGraphNode(neighbor.label)
                    hashmap[curr].neighbors.append(copy)
                    hashmap[neighbor] = copy
                    queue.append(neighbor)
        return new_head
