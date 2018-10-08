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


// 准备好完整地建立一个用邻接矩阵表示的图了
// 通常我们的输入格式是这样的，就是先给你所有的顶点个数，给你总的边数，然后接下来有这么多行，每行给出一条边的信息，
// 也就是边的初始点，终点，以及它的权重，等等，针对这个输入格式，我们来写一个函数，叫做BuildGraph,那么在这个函数里面，
// 我们就是要申明这么一个图，最后在这一个地方把它建好，然后返回
MGraph BuildGraph(){
    MGraph Graph;
    int Nv;
    scanf("%d", &Nv);  // 首先读进来一个顶点数，这里相信你会有疑问，这个顶点数和边数不是一起给的吗？我干嘛不一起读进来呢？我是有道理的，看到后面就明白了
    Graph = CreateGraph(Nv);  // 我不需要知道边数，只要有这个顶点数以后，我就可以初始化一个图了，初始化的这个图呢，是有所有的顶点，但是一条边都没有的Graph
    scanf("%d", &Graph->Ne);   // 然后我再读这个边数，就直接读的是Graph-Ne, 也就是说我不用另外去申明一个临时变量Ne,读进来，然后再把它赋值给Graph->Ne, 我可以在建立了这个Graph之后，直接把它读进来，那么如果读进来的边数等于0的话，说明本身这个图就没有一条边，那么到这一步以后，我们就已经完成了，所以到这里就直接return Graph,就结束了
    if (Graph->Ne != 0){  // 如果有边的话，我们就要把一条一条边读进来，然后插到图里面去，用Edge,所以在调用它之前呢，我们先要申明一个临时边的结点，去临时的存一下这个边，然后我们就进入了一个简单的循环，在每一次循环里面，我们把一条边的信息读进来，然后调用了我们前面实现的InsertEdge，把这条边插到图里，然后就完成了任务
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0; i<Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}


// 考场上的简单实现方法
int G[MAXN][MAXN], Nv, Ne;
void BuildGraph(){
    int i, j, v1, v2, w;

    scanf("%d", &Nv);
    // CreateGraph
    for(i=0; i<Nv; i++)
        for(j=0; j<Nv; j++)
            G[i][j] = 0
    scanf("%d", &Ne);
    for(i=0; i<Ne; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        // InsertEdge
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}


#define MAXN 10
int G[MAXN][MAXN], Nv, Ne;


void BuildGraph(){
    int i, j, v1, v2, w;
    scanf("%d", &Nv);
    for(i=0; i<Nv; i++)
        for(j=0; j<Nv; j++)
            G[i][j] = 0;
    scanf("%d", &Ne);
    for(i=0; i<Ne; i++){
        scanf("%d %d %d", &v1, &v2, &w);
        G[v1][v2] = w;
        G[v2][v1] = w;
    }
}


// https://www.cnblogs.com/ranjiewen/p/6701850.html
// https://blog.csdn.net/wanmeiwushang/article/details/52841900
// 比较好的方案
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
#define MaxSize 10
int Graph[MaxSize][MaxSize], DFS_Visited[MaxSize], BFS_Visited[MaxSize], Nv, Ne;


void DFS(int v){
    DFS_Visited[v] = 1;  // 1表示已经访问过了
    printf(" %d", v);
    for(int i=0; i<Nv; i++){
        if(Graph[v][i]==1&&!DFS_Visited[i]){
            DFS(i);  // 利用二维数组的一行就是该节点的邻接点，如果那个邻接点还没没访问过则递归访问
        }
    }
}


void BFS(int v){
    BFS_Visited[v] = 1;
    queue<int> q;
    q.push(v);
    printf(" %d", v);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(int i=0; i<Nv; i++){
            if(Graph[temp][i]==1&&!BFS_Visited[i]){
                printf(" %d", i);
                BFS_Visited[i] = 1;
                q.push(i);
            }
        }
    }
}


int main(){
    int V1, V2;
    scanf("%d %d", &Nv, &Ne);
    for(int i=0; i<Ne; i++){
        scanf("%d %d", &V1, &V2);
        Graph[V1][V2] = 1;
        Graph[V2][V1] = 1;
    }
    for(int i=0; i<Nv; i++){
        if(!DFS_Visited[i]){
            putchar('{');
            DFS(i);
            printf(" }\n");
        }
    }
    for(int i=0; i<Nv; i++){
        if(!BFS_Visited[i]){
            putchar('{');
            BFS(i);
            printf(" }\n");
        }
    }
    return 0;
}



