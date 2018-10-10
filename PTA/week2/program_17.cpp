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
            q.pop();
            vec.push_back(node);
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