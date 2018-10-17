//
// Created by zhang on 2018/10/16.
//
#include <cstdio>
using namespace std;
struct node{
    int id, layer;
};
#define MaxSize 101
int Graph[MaxSize][MaxSize], N, M;


void initGraph(int n){
    for(int i=1; i<n; i++)
        for(int j=1; j<n; j++)
            Graph[i][j] = 0;
}


void insertEdge(int i, int j, int weight){
    Graph[i][j] = weight;
    Graph[j][i] = weight;
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