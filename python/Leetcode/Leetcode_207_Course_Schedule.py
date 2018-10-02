#! python3
# -*- coding: utf-8 -*-


class Solution(object):
    def make_graph(self, numCourses, prerequisites):
        graph = [[] for _ in range(numCourses)]
        for prerequisite in prerequisites:
            graph[prerequisite[1]].append(prerequisite[0])
        return graph

    def compute_indegree(self, graph):
        # 与顶点v关联的边数，称为v的度数
        degrees = [0] * len(graph)
        for neighbors in graph:
            for neighbor in neighbors:
                degrees[neighbor] += 1
        return degrees

    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        2, [[1, 0]]  一共有2门备选课程。要选择课程1， 必须先完成课程0。因此这是可能的。
        2, [[1,0],[0,1]] 一共有2门备选课程。要选择课程1，必须先完成课程0，而要修课程0，必须修完课程1 因此这是不可能的
        此问题等价于判断有向图中是否有环。如果存在环路，无法完成拓扑排序，也就不可能修完所有的课程。

        拓扑排序的定义:
        每一顶点都不会通过边，指向其在此序列中的前驱顶点，这样的一个线性序列，称作原有向图的一个拓扑排序
        dfs bfs都可以解决这道问题
        bfs:
        L <- Empty list that will contain the sorted elements
        S <- Set of all nodes with no incoming edge
        while S is non-empty do
            remove a node n from S
            add n to tail of L
            for each node m with an edge e from n to m do
                remove edge e from the graph
                if m has not other incoming edges then
                    insert m into S
        if graph has edges then
            return error  (graph has at least one cycle)
        else
            return L (a topologically sorted order)

        BFS uses the indegrees of each node, we will first try to find a node with 0 indegree.
        if we fail to do so, there must be a cycle in the graph and we return false

        DFS: One is to record all the visited nodes and the other is to record the visited nodes in the current DFS
        visit
        """
        graph = self.make_graph(numCourses, prerequisites)
        degrees = self.compute_indegree(graph)
        print(graph)
        print(degrees)
        for i in range(numCourses):
            j = 0
            for j in range(numCourses):
                if not degrees[j]:
                    break
            if j == numCourses:
                return False
            degrees[j] = -1
            for neighbor in graph[j]:
                degrees[neighbor] -= 1
        return True
# 上面的写法有问题


# 先来看BFS的解法，我们定义二维数组graph来表示这个有向图，一位数组in来表示每个顶点的入度
# 我们开始根据输入来建立这个有向图，并将入度数组也初始化好
# 然后我们定义一个queue变量，将所有入度为0的点放入队列中，然后开始遍历对列，从graph里遍历其连接的点
# 每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。直到遍历完队列中的所有的值，
# 若此时还有节点的入度不为0，则说明环存在，返回false, 反之则返回true
# 入度: 存在于有向图中，所有接入该点的边数之和
# 出度: ...
"""
dfs伪码描述：
public void DFS(Vertex v){
    visited[v] = true;
    for(v 的每个邻接点 W){
        if (!visited[W]){
            DFS(W);
        }
    }
}

bfs: 浅尝辄止，也需要一个队列以保持遍历过的顶点顺序，以便按出队的顺序再去访问这些顶点的邻接顶点
1. 顶点 v 入队列
2. 当队列非空时则继续执行，否则算法结束
3. 出队列取得队头顶点 v；访问顶点 v 并标记顶点 v 已被访问
4. 查找顶点 v 的第一个邻接顶点 col
5. 若 v 的邻接顶点 col 未被访问过的，则 col 继续
6. 查找顶点 v 的另一个新的邻接顶点 col，转到步骤5入队列，直到顶点 v 的所有未被访问过的邻接点处理完。转到步骤2
"""


class Solution0(object):
    """
    2, [[1, 0]]  一共有2门备选课程。要选择课程1， 必须先完成课程0。因此这是可能的。 0 -> 1(入度为1，出度为0)
    2, [[1,0],[0,1]]  一共有2门备选课程。要选择课程1，必须先完成课程0，而要修课程0，必须修完课程1
    等同问题是有向图检测环，vertex是course, edge是prerequisite
    我觉得一般会使用Topological Sorting拓扑排序来检测。一个有向图假如有环则不存在Topological Order。一个DAG的Topological Order可以有大于1种。 常用的Topological Sorting算法有两种
    http://www.cnblogs.com/yrbbest/p/4493547.html
    """
    def canFinish(self, numCourses, prerequisites):
        graph = [[] for _ in range(numCourses)]
        in_degrees = [0] * numCourses
        for prerequisite in prerequisites:
            graph[prerequisite[1]].append(prerequisite[0])
            in_degrees[prerequisite[0]] += 1
        queue = []
        for i in range(numCourses):
            if in_degrees[i] == 0:
                queue.append(i)
        res = []
        while len(queue) > 0:
            src = queue.pop()
            res.append(src)
            for dest in graph[src]:
                in_degrees[dest] -= 1
                if in_degrees[dest] == 0:
                    queue.append(dest)
        return len(res) == numCourses


class Solution1(object):
    """
    BFS
    Kahn's Algorithms (wiki)： BFS based， start from with vertices with 0 incoming edge，insert them into list S，at the same time we remove all their outgoing edges，after that find new vertices with 0 incoming edges and go on. 详细过程见Reference里Brown大学的课件。
    [[1,0]]  一共有2门备选课程。要选择课程1， 必须先完成课程0。因此这是可能的。 0 -> 1
    所以入度为0的结点是0
    """
    def canFinish(self, numCourses, prerequisites):
        if numCourses < 0 or prerequisites is None:
            return False
        if len(prerequisites) == 0:
            return True
        adjacencyListGraph = [[] for _ in range(numCourses)]
        inDegrees = [0] * numCourses
        for prerequisite in prerequisites:
            adjacencyListGraph[prerequisite[1]].append(prerequisite[0])
            inDegrees[prerequisite[0]] += 1
        print(adjacencyListGraph)
        print(inDegrees)
        queue = []
        for i in range(numCourses):
            if inDegrees[i] == 0:
                queue.append(i)
        print(queue)
        res = []
        while len(queue) > 0:
            src = queue.pop()
            res.append(src)
            for dest in adjacencyListGraph[src]:
                inDegrees[dest] -= 1  # remove all outgoing edges, at each iteration we only visit outgoing edges from popped vertex. So every edge visited once
                # 一位数组in来表示每个顶点的入度。我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。然后我们定义一个queue变量，将所有入度为0的点放入队列中，然后开始遍历队列，从graph里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回false，反之则返回true。
                if inDegrees[dest] == 0:
                    queue.append(dest)
        return len(res) == numCourses


class Solution2(object):
    """
    DFS
    Tarjan's Algorithms (wiki)： DFS based， loop through each node of the graph in an arbitrary order，initiating a depth-first search that terminates when it hits any node that has already been visited since the beginning of the topological sort or the node has no outgoing edges (i.e. a leaf node).
    没有看懂
    """
    def canFinish(self, numCourses, prerequisites):
        if numCourses < 0 or prerequisites is None:
            return False
        if len(prerequisites) == 0:
            return True
        adjacencyListGraph = [[] for _ in range(numCourses)]
        for prerequisite in prerequisites:
            adjacencyListGraph[prerequisite[1]].append(prerequisite[0])

        visited = [False for _ in range(numCourses)]
        onVisitingPath = [False for _ in range(numCourses)]

        for i in range(numCourses):
            if not visited[i] and not self.check(i, adjacencyListGraph, visited, onVisitingPath):
                return False
        return True

    def check(self, courseNum, adjacencyListGraph, visited, onVisitingPath):
        if visited[courseNum]:
            return True
        onVisitingPath[courseNum] = True
        for dependent in adjacencyListGraph[courseNum]:
            if onVisitingPath[dependent] or (not visited[dependent] and not self.check(dependent, adjacencyListGraph, visited, onVisitingPath)):
                return False
        onVisitingPath[courseNum] = False
        visited[courseNum] = True
        return True


class Solution3(object):
    """
    http://www.cnblogs.com/grandyang/p/4484571.html
    还是dfs
    """
    def canFinish(self, numCourses, prerequisites):
        graph = [[] for _ in range(numCourses)]
        visit = [0] * numCourses
        for prerequisite in prerequisites:
            graph[prerequisite[1]].append(prerequisite[0])
        print(graph)
        print(visit)
        for i in range(numCourses):
            if not self.canFinishDFS(graph, visit, i):
                return False
        return True

    def canFinishDFS(self, graph, visit, i):
        if visit[i] == -1:
            return False
        if visit[i] == 1:
            return True
        visit[i] = -1
        for a in graph[i]:
            if not self.canFinishDFS(graph, visit, a):
                return False
        visit[i] = 1
        return True


if __name__ == '__main__':
    # solution = Solution()
    # res = solution.canFinish(2, [[1, 0], [0, 1]])
    # print(res)
    # solution = Solution0()
    # solution.canFinish(2, [[1, 0], [0, 1]])
    # solution = Solution1()
    # res1 = solution.canFinish(2, [[1, 0]])
    # res2 = solution.canFinish(2, [[1, 0], [0, 1]])
    # print(res1)
    # print(res2)
    # solution = Solution2()
    # res1 = solution.canFinish(2, [[1, 0]])
    # print(res1)
    # res2 = solution.canFinish(2, [[1, 0], [0, 1]])
    # print(res2)
    solution = Solution3()
    res1 = solution.canFinish(2, [[1, 0]])
    res2 = solution.canFinish(2, [[1, 0], [0, 1]])
    print(res1)
    print(res2)
