//
// Created by zhang on 2018/10/10.
//
/*
 * dfs方法有误
#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;
#define MaxSize 10000
int Graph[MaxSize][MaxSize], N, M, DFS_Visited[MaxSize];  // N结点数 M边数


int DFS(int start, int distance, int count){
    DFS_Visited[start] = 1;
    for(int i=0; i<N; i++){
        if(Graph[i][start]==1&&!DFS_Visited[i]){
            distance = i-start;
            if (distance>6){
                exit(1);
            }
            else{
                count++;
                DFS(i, distance, count);
            }
        }
    }
    return count;
}


int main(){
    cin>>N>>M;
    int v1, v2;
    for(int i=0; i<M; i++){
        cin>>v1>>v2;
        Graph[v1][v2] = 1;
        Graph[v2][v1] = 1;
    }
    for(int i=1; i<=N; i++){
        if(!DFS_Visited[i]){
            int qualified = DFS(i, 0, 1);  // 自己本身的点也要包括进去
            double ratio = qualified / (double)N;
            cout<<i<<':'<<" "<<setprecision(2)<<ratio*100<<'%'<<endl;
        }
    }
}
*/
// https://blog.csdn.net/flx413/article/details/53256980
// https://www.cnblogs.com/ranjiewen/p/6771945.html
/*
#include <cstdio>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 10001
int MGraph[MAX][MAX];
int visit[MAX] = {0};


void InitGraph(int n){
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            MGraph[i][j] = 0;
}


void InsertEdge(int i, int j){
    MGraph[i][j] = 1;
    MGraph[j][i] = 1;
}


double BFS(int currNode, int n){
    queue<int> q;
    q.push(currNode);
    visit[currNode] = 1;

    int count = 1;
    for(int level=0; level<6; level++){
        vector<int> vec = {0};
        while(!q.empty()){
            int node = q.front();
            vec.push_back(node);
            q.pop();
        }
        for(int i=0; i<vec.size(); i++){
            int node = vec[i];
            for(int j=1; j<=n; j++){
                if(!visit[j]&&MGraph[node][j]==1){
                    q.push(j);
                    visit[j] = 1;
                    count++;
                }
            }
        }
    }
    double rate = (double)count / (double) n;
    return rate * 100.0;
}


int main(){
    int N, E;
    scanf("%d%d", &N, &E);

    InitGraph(N);

    int a, b;
    for(int i=0; i<E; i++){
        scanf("%d%d", &a, &b);
        InsertEdge(a, b);
    }

    for(int i=1; i<=N; i++){
        memset(visit, 0, sizeof(visit[0])*(N+1));
        double r = BFS(i, N);
        printf("%d: %.2lf%%\n", i, r);
    }

    return 0;
}
*/
/* 这题顶点的数量很大，边较少，所以采用邻接表来实现了。
 * */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;


#define MaxVertexNum 10000  // 最大顶点数
typedef int Vertex;  //  用顶点下标表示顶点
typedef int WeightType;  // 边的权值设为整型
typedef char DataType;  // 顶点存储的数据类型设为字符型


/*边的定义*/
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1, V2;  // 有向边<V1, V2>
};
typedef PtrToENode Edge;

/*邻接点的定义*/
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;  // 邻接点下标
    PtrToAdjVNode Next;  // 指向下一个邻接点的指针
};


/*顶点表头结点的定义*/
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;  // 边表头指针
}AdjList[MaxVertexNum];  // AdjList是邻接表类型


/*图结点的定义*/
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;  /*顶点数*/
    int Ne;  /*边数*/
    AdjList G;  /*邻接表*/
};
typedef PtrToGNode LGraph;  // 以邻接表方式存储的图类型
bool Visited[MaxVertexNum] = {false};


LGraph CreateGraph(int VertexNum);
void InsertEdge(LGraph Graph, Edge E);
LGraph BuildGraph();
void Visit(Vertex V);
void InitVisited();
int BFS(LGraph Graph, Vertex V, void (*Visit)(Vertex));


LGraph CreateGraph(int VertexNum)
{
    // 初始化一个有VertexNum个顶点但没有边的图
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));  // 建立图
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    /*初始化邻接表头指针*/
    /*注意：这里默认顶点编号从0开始，到(Graph->Nv-1)*/
    for(V=0; V<Graph->Nv; V++)
        Graph->G[V].FirstEdge = NULL;

    return Graph;
}


void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;

    /*插入边<V1, V2>*/
    /*为V2建立新的邻接点*/
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;

    /*将V2插入V1的表头*/
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;  // 这里还是有点难理解的，可以看下我的专栏里的图

    /*若是无向图，还要插入边<V2, V1>*/
    /*为V1建立新的邻接点*/
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;

    /*将V1插入V2的表头*/
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;
}


LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv, i;

    scanf("%d", &Nv);  // 读入顶点个数
    Graph = CreateGraph(Nv); // 初始化有Nv个顶点但没有边的图

    scanf("%d", &(Graph->Ne));  // 读入边数
    if(Graph->Ne != 0){  // 如果有边，即输入的边数不为0
       E = (Edge)malloc(sizeof(struct ENode))  // 建立边节点
       // 读入边，格式为"起点 终点" 插入邻接矩阵
       for(i=0; i<Graph->Ne; i++){
           scanf("%d %d", &E->V1, &E->V2);
           InsertEdge(Graph, E);
       }
    }

    return Graph;
}


// 初始化Visited[] = false
void InitVisited()
{
    for(int i=0; i<MaxVertexNum; i++)
        Visit[i] = false;
}

/* 本题的关键在于 如何记录节点当前的层数
 * 引入2个变量 last tail 分别指向 当前层数的最后一个元素  和 下一层的最后一个元素
 * 若当前出队的元素与last相等 则说明即将进入下一层 将last更新为tail 更新tail 重复~~直到level=6或者队列空
 * 用tail记录最后进队的元素，last = tail记录该层tail的值。当last出队时代表层数++
 * */
int BFS(LGraph Graph, Vertex V)
{
    queue<Vertex> Q;
    Vertex W;
    int count = 1;
    int level = 0;
    Vertex last = V, tail;  // last与V的值相等, tail值为1
    Visited[V] = true;  // 标记V已访问
    Q.push(V);

    while(!Q.empty()){
        W = Q.front();
        Q.pop();
        for(PtrToAdjVNode tempV = Graph->G[W].FirstEdge; tempV; tempV=tempV->Next)  /*对W的每个邻接点tempV->AdjV*/
            if(!Visited[tempV->AdjV]){
                Visited[tempV->AdjV] = true;
                Q.push(tempV->AdjV);
                count++;
                tail = tempV->AdjV;  // tail是下一层的最后一个元素
            }
        if(W == last) {
            level++;
            last = tail;
        }
        if(level == 6)
            break;
    }
    return count;
}


int main()
{
    LGraph graph;
    graph = BuildGraph();
    for(int i=1; i<=graph->Nv; i++){
        InitVisited();
        int count = BFS(graph, i);
        printf("%d: %.2f%%\n", i, count*100.0/graph->Nv);
    }

    return 0;
}



// 邻接矩阵实现
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
bool map[10001][10001] = {false};
int n, m;
int Count;
void bfs(int x){
    bool visited[10001] = {false};
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int level = 0;  // 记录层数
    int last = x;  // 记录当前层数的最后一个元素
    int tail;  // 指向下一层最后一个元素
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i=1; i<=n; i++){
            if(!visited[i] && map[x][i] == 1){
                q.push(i);
                Count++;
                visited[i] = true;
                tail = i;  // 我的理解是，在图中，每个当前层的节点与下一个节点有连接时，都是在下一层的节点，在头脑中想象一下图是怎么画的
            }
        }
        if(last == x){  // x为当前遍历的结点，当遍历到当前层的最后一个元素时，记录下一层
            level++;
            last = tail;
        }
        if(level == 6)
            break;
    }
}


int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int k, l;
        cin>>k>>l;
        map[k][l] = 1;
        map[l][k] = 1;
    }
    for(int i=1; i<=n; i++){  /*对于所有节点做bfs()*/
        Count = 1;  // 全局变量
        bfs(i);
        cout << i << ": ";
        float answer = (float)Count / n * 100;
        printf("%.2f%%\n", answer);
    }

    return 0;
}
