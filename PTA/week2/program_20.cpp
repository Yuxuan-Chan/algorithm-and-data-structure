//
// Created by zhang on 2018/10/25.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;


#define ERROR -1
#define MaxVertexNum 505
#define INFINITY 65535


typedef int Vertex;  // 用顶点下标表示顶点，为整型
typedef int WeightType;  // 边的权重类型为整型


/*边的定义*/
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;
    WeightType Weight;  // 长度
    WeightType Cost;  // 过路费
};
typedef PtrToENode Edge;


/*图节点的定义*/
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];  // 邻接矩阵存放路径长度
    WeightType Cost[MaxVertexNum][MaxVertexNum];  // 邻接矩阵存放过路费
};
typedef PtrToGNode MGraph;


MGraph CreateMGraph(int VertexNum) {
    /*初始化一个有VertexNum个顶点但没有边的图*/
    Vertex V, W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Ne = 0;
    Graph->Nv = VertexNum;

    /*初始化邻接矩阵*/
    /*注意: 这里默认顶点编号从0开始, 到（Graph->Nv-1)*/
    for(V=0; V<Graph->Nv; V++){
        for(W=0; W<Graph->Nv; W++){
            Graph->G[V][W] = INFINITY;
            Graph->Cost[V][W] = INFINITY;
        }
    }
    return Graph;
}


void InsertMEdge(MGraph Graph, Edge E){
    /*插入边<V1, V2>*/
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->Cost[E->V1][E->V2] = E->Cost;
    /*若是无向图，还要插入边*/
    Graph->G[E->V2][E->V1] = E->Weight;
    Graph->Cost[E->V2][E->V1] = E->Cost;
}


MGraph BuildMGraph(int Nv, int Ne){
    MGraph Graph;
    Edge E;
//    Vertex V;

    Graph = CreateMGraph(Nv);  /*初始化有Nv个顶点但没有边的图*/

    Graph->Ne = Ne;
    if(Graph->Ne!=0){
        E = (Edge)malloc(sizeof(struct ENode));
        /*读入边，格式为"起点 终点 长度 收费额"， 插入邻接矩阵*/
        for(int i=0; i<Graph->Ne; i++){
            scanf("%d %d %d %d", &E->V1, &E->V2, &E->Weight, &E->Cost);
            InsertMEdge(Graph, E);
        }
    }
    return Graph;
}


//从未被收录顶点中找到dist最小者
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]){
    Vertex MinV, V;
    int MinDist = INFINITY;
    for(V=0; V<Graph->Nv; V++){
        if(collected[V]==false&&dist[V]<MinDist){  // 若v未被收录，且dist[V]更小
            MinDist = dist[V];  // 更新最小距离
            MinV = V;  // 更新对应顶点
        }
    }
    if(MinDist<INFINITY){  // 若找到了最小的dist
        return MinV;   // 返回对应顶点的下标
    }
    else{
        return ERROR;  // 若这样的顶点不存在，返回错误标记
    }
}


bool Dijkstra(MGraph Graph, int dist[], int cost[], int path[], Vertex S){
    int collected[MaxVertexNum];
    Vertex V, W;
    /*初始化: 此处默认邻接矩阵中不存在的边用INFINITY表示*/
    for(V=0; V<Graph->Nv; V++){
        dist[V] = Graph->G[S][V];
        path[V] = -1;
        collected[V] = false;
        cost[V] = Graph->Cost[S][V];
    }

    /*先将起点收入集合*/
    dist[S] = 0;
    cost[S] = 0;
    collected[S] = true;

    while(1){
        /*V=未被收录顶点中dist最小者*/
        V = FindMinDist(Graph, dist, collected);
        if(V==ERROR){
            break;  //这样的V不存在，跳出循环
        }
        collected[V] = true;  // 收录到集合中
        for(W=0; W<Graph->Nv; W++){
            /*若V是W的邻接点并且未被收录*/
            if(collected[W]== false&&Graph->G[V][W]<INFINITY){
                if(Graph->G[V][W]<0){
                    return false;  // 有负边，返回错误
                }
                /*若收录V使得dist[]变小*/
                if(dist[V]+Graph->G[V][W]<dist[W]){
                    dist[W] = dist[V] + Graph->G[V][W];  // 更新dist[W]
                    path[W] = V;  // 更新S到W的路径
                    cost[W] = cost[V] + Graph->Cost[V][W];
                }
                else if (dist[V]+Graph->G[V][W]==dist[W]){
                    if(cost[W]>cost[V]+Graph->Cost[V][W]){
                        cost[W] = cost[V] + Graph->Cost[V][W];
                        path[W] = V;  // 更新路径
                    }
                }
            }
        }
    }
    return true;
}


int main(){
    // 顶点数N城市数 边数M公路数 出发地S 目的城市D
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    MGraph graph;
    graph = BuildMGraph(N, M);

    WeightType dist[MaxVertexNum] = {INFINITY};
    WeightType cost[MaxVertexNum] = {INFINITY};
    WeightType path[MaxVertexNum] = {0};
//    int collected[MaxVertexNum] = {false};

    Dijkstra(graph, dist, cost, path, S);

    cout << dist[D] << " " << cost[D] << endl;

    return 0;
}