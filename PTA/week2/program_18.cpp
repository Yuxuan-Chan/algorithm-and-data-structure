//
// Created by zhang on 2018/10/16.
// https://www.cnblogs.com/ranjiewen/p/6719005.html
// 这块知识确实有点薄弱
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;


#define MaxVertexNum 100  // 最大顶点数设为100
#define INFINITY 65535  // 设为双字节无符号正数的最大值65535
typedef int Vertex;  // 用顶点下标表示顶点，为整型
typedef int WeightType;  // 边的权值设为整型


/*边的定义*/
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;  // 有向边<V1, V2>
    WeightType Weight;  // 权重
};
typedef PtrToENode Edge;


/*图结点的定义*/
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  // 顶点数
    int Ne;  // 边数
    WeightType G[MaxVertexNum][MaxVertexNum];  // 邻接矩阵
};
typedef PtrToGNode MGraph;  // 以邻接矩阵存储的图类型


MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildGraph();
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum]);
WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int N);
void FindAnimal(MGraph Graph);


int main()
{
    MGraph graph;
    graph = BuildGraph();
    FindAnimal(graph);
    return 0;
}


MGraph CreateGraph(int VertexNum)
{
    /* 初始化一个有VertexNum个顶点但没有边的图 */
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    /*初始化邻接矩阵*/
    /*注意: 这里默认顶点编号从0开始，到(Graph->Nv-1)*/
    for(V=0; V<Graph->Nv; V++)
        for(W=0; W<Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;

    return Graph;
}


void InsertEdge(MGraph Graph, Edge E)
{
    /*插入边<V1, V2>*/
    Graph[E->V1][E->V2] = E->Weight;
    /*若是无向图, 还要插入边<V2, V1>*/
    Graph[E->V2][E->V1] = E->Weight;
}


MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv, i;

    scanf("%d", &Nv);  /*读入顶点个数*/
    Graph = CreateGraph(Nv);  /*初始化有Nv个顶点但没有边的图*/

    scanf("%d", &(Graph->Ne));  /*读入边数*/
    if(Graph->Ne != 0){  /*如果有边*/
        E = (Edge)malloc(sizeof(struct ENode));  /*建立边节点*/
        /*读入边，格式为“起点 终点 权重”，插入邻接矩阵*/
        for(i=0; i<Graph->Ne; i++){
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            E->V1--;  // 编号从0开始
            E->V2--;
            /* 注意：如果权重不是整型，Weight的读入格式要改 */
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}


/*邻接矩阵存储 - 多源最短路算法*/
void Floyd(MGraph Graph, WeightType D[][MaxVertexNum])
{
    // Floyd算法定义了一个二维数组，也就是一个矩阵
    Vertex i, j, k;

    /*初始化*/
    for(i=0; i<Graph->Nv; i++)
        for(j=0; j<Graph->Nv; j++)
            D[i][j] = Graph->G[i][j];

    for(k=0; k<Graph->Nv; k++)
        for(i=0; i<Graph->Nv; i++)
            for(j=0; j<Graph->Nv; j++)
                if(D[i][k]+D[k][j]<D[i][j]){
                    D[i][j] = D[i][k]+D[k][j];
                }

}


void FindAnimal(MGraph Graph)
{
    WeightType D[MaxVertexNum][MaxVertexNum], MaxDist, MinDist;
    Vertex Animal;

    Floyd(Graph, D);

    MinDist = INFINITY;
    for(Vertex i=0; i<Graph->Nv; i++){
        MaxDist = FindMaxDist(D, i, Graph->Nv);
        if(MaxDist==INFINITY){  //说明有从i无法变出的动物 //表示图有不连通的，该动物不能变成任何其他动物
            printf("0\n");
            return;
        }
        if(MinDist>MaxDist){  //找到最长距离更小的动物
            MinDist = MaxDist;  //更新距离
            Animal = i+1;  // 记录编号
        }
    }
    printf("%d %d\n", Animal, MinDist);
}


WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex i, int N)
{
    WeightType MaxDist;
    MaxDist = 0;
    for(Vertex j=0; j<N; j++){  //找出i到其他动物j的最长距离
        if(i!=j&&D[i][j]>MaxDist){
            MaxDist = D[i][j];
        }
    }
    return MaxDist;
}

/*
 * void BFS(Vertex S)
 * {
 *    visited[S] = true;
 *    Enqueue(S, Q);
 *    while(!Q.empty()){
 *      V = Dequeue(Q);
 *      for(V的每个邻接点W)
 *        if(!visited[W]){
 *          visited[W] = true;
 *          Enqueue(W, Q);
 *        }
 *    }
 * }
 * 最短路径算法将在BFS算法的基础上进行改进，其实visited这个东西是不需要的
 *
 * void Unweighted(Vertex S)
 * {
 *  Enqueue(S, Q);
 *  while(!IsEmpty(Q)){
 *    V = Dequeue(Q);
 *    // 当一个顶点被弹出来的时候，就意味着这个顶点到S的最短路已经被找到了，
 *    // 也就是dist[V]是已经被算好了的，算好了我才把它压进去的，等它弹出来以后呢，
 *    // 我们就要往外扩展一步，也就是对V的每个邻接点W, 要去判断W有没有被访问过
 *    // W如果没有被访问过，它一定是等于一个很奇特的值，比如在这里头，我把它初始化-1
 *    for(V的每个邻接点W)
 *      if( dist[W] == -1){
 *          // 如果它没有被访问过，我要访问它，它的距离是什么？它的距离应该是它的前一个顶点，V的距离，
 *          // 然后再加1，所以dist[W]应该被更新为dist[V]加上1(dist[W] = dist[V] + 1)
 *          // 那么谁是S到W必经的顶点呢？就是它的前一个顶点V(path[W]=V)
 *          // 记录path这个数组，它会有什么用呢？想一下，当我们整个程序完成后，比如说我指定了某个顶点W
 *          // 要求你把从S到W的路径打印出来，要怎么去做呢？首先你去看一下这个path[W]等于多少，
 *          // 它等于的这个数一定是在它前面的那个顶点的编号，是个V, 然后下一步你就要去看path[V]等于多少
 *          // path[V]的值就是访问V之前的那一个顶点它的编号，于是可以顺着path这个数组一个一个往前推，
 *          // 一直推到源点，就可以得到一个反向的路径，从W到S的路径，那要得到S到W的路径，很简单，利用堆栈
 *          dist[W] = dist[V] + 1;
 *          path[W] = V;
 *          Enqueue(W, Q);
 *      }
 *  }
 * }
 *
 * 有权图的单源最短路算法
 * 引出Dijkstra算法，每次从没有收录的顶点中收录一个dist最小的把它收进集合就好，这种思想就是贪心算法的思想
 * void Dijkstra(Vertex s)
 * {
 *  while(1){
 *    V = 未收录顶点中dist最小者;
 *    if (这样的V不存在)
 *      break;
 *    collected[V] = true;
 *    for(V的每个邻接点W)
 *      if(collected[W] == false)
 *        if(dist[V]+E<v,w> < dist[W]){
 *          dist[W] = dist[V] + E<v, w>;
 *          path[W] = V;
 *        }
 *  }
 * }
 *
 * 多源最短路径算法引出Floyd
 * 利用邻接矩阵来表示稠密图，Floyd算法定义了一个二维数组
 * void Floyd()
 * {
 *  for(i = 0; i < N; i++)
 *    for(j = 0; j < N; j++){
 *      D[i][j] = G[i][j];  // D[i][j]初始化就是它的邻接矩阵
 *    }
 *  for(k = 0; k < N; k++)
 *    for(i = 0; i < N; i++)
 *      for(j = 0; j < N; j++)
 *        if(D[i][k] + D[k][j] < D[i][j]){
 *          D[i][j] = D[i][k] + D[k][j];  // i到j之间的最短路径，最短路径一定是从i到k的路径，加上k, 加上k到j的最短路径这么三段组成的
 *        }
 * }
 *
 * void DFS(Vertex S)
 * {
 *   visited[S] = true;
 *   for(S的每个邻接点W){
 *     if(!visited[W]){
 *       DFS(W);
 *     }
 *   }
 * }
 * */