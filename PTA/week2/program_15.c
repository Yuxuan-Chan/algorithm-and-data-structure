//
// Created by zhang on 2018/10/6.
//
#include <stdio.h>
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  // 顶点数
    int Ne;  // 边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];  // 存顶点的数据
};
typedef PtrToGNode MGraph;  // 以邻接矩阵存储的图类型
typedef int Vertex;  // 用顶点下标表示顶点，为整型
// 用邻接矩阵表示图，主要就是一个矩阵，也就是在程序里对应的二维数组，如果vi和vj是有一条边的话，那么相应的第i,j个元素就等于1，如果没有边的
// 话就等于0，这是无权图的情况，如果这个图是有权的话，那么当有一条边的时候，应该对应的是它的权重，没有边的时候，有可能是0，有可能是无穷大
MGraph CreateGraph(int VertexNum){  // 初始化一个有VertexNum个顶点但没有边的图，先把顶点建立起来，一个图里面可以一条边都没有，按时不能一个顶点都没有
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

//    Graph->G[V][W] = 0;   // 我们默认顶点的编号是从0开始的，一直到Nv-1, 可能呢，一开始你不太习惯，通常我们的循环变量都是用i和j的，为什么在这里要用v和w呢，在前面把v和w定义为顶点类型
    for(V=0; V<Graph->Nv; V++)
        for(W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = 0;

    return Graph;
}


// 前面已经初始化了一个有所有的顶点但是一条边都没有的图，接下来就是每次向这个图里面插入一条边
// Edge边的类型定义，其实每一种结构都可以模仿刚才图结点的定义，先定义一个边结点，然后定义它的PtrToENode
// 就是指向边结点的指针(即typedef struct ENode *PtrToENode)，然后把边定义为指向结点的指针，(typedef PtrToENode Edge),
// 当我们要插入一条边的时候，就把这个指针传进去，
typedef struct ENode *PtrToENode;
struct ENode {
   Vertex V1, V2;  // 有向边<V1, V2>
   WeightType Weight;  // 权重
};
// 哪些东西决定了一条边呢？一条边是由两个顶点来决定的
// 如果我们在讨论一个从V1指向V2的有向边的时候，那我们就定义一个顶点是它的出发点，一个顶点是它的终点，那除了这两个顶点之外，还可能有什么呢？
// 如果我们在讨论无权图的话呢，这样就可以了，如果是有权图的话呢，那当然还得定义一个权重，那么这个权重的类型，是WeightType,跟我们前面邻接矩阵的类型是一致的
// 对于邻接矩阵来说呢，插入一条边是一件非常简单的事情，就是把相应的权重赋给相应的邻接矩阵的元素就可以了，所以如果我们插入的是V1,V2的话，那么就把这个Graph里面，邻接矩阵对应的V1和V2的这个元素赋值为边上面的权重
// 当然如果我们说的是无向图的话，其实我们是要插入两条边的，如果是无向图的话，还要把V2,V1也插进去，也就是把Graph里面的Graph->G[E->V2][E->V1] = E->Weight赋值为它的权重，就完成这个插入
typedef PtrToENode Edge;


void InsertEdge(MGraph Graph, Edge E){
    // 插入边<V1, V2>
    Graph->G[E->V1][E->V2] = E->Weight;

    // 若是无向图，还要插入边<V2, V1>
    Graph->G[E->V2][E->V1] = E->Weight;
}

// 3 5
// 将5的桶装满，倒入3的桶中，再将3桶的剩下的水倒掉，将5桶剩下的2升水倒入3桶中，再将5桶的水接满，倒入3桶中，5桶剩下的就是4升水
void DFS(Vertex V){  // 类似于树的先序遍历
    visited[V] = true;
    for(V 的每个邻接点 W)
        if(!visited[W])
            DFS(W);
}


void BFS(Vertex V){  // 层次遍历
    visited[V] = true;
    Enqueue(V, Q);
    while(!IsEmpty(Q)){
        V = Dequeue(Q);
        for(V 的每个邻接点 W){
            if (!visited[W]){
                visited[W] = true;
                Enqueue(W, Q);
            }
        }
    }
}






