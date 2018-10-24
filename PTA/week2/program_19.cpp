//
// Created by zhang on 2018/10/22.
//
/*
 * 两种解决思路
 * 方法一: dijkstra 对第一跳做处理。每一个第一跳dijkstra，如果跳的步少，更新存储鳄鱼下标。如果相同，加入。
 * （用vector很方便）。然后找到第一步跳的最少的。题目保证唯一。从第一步跳的最少的，再一次dijkstra，剩下的就是模板问题了，好好背吧。
 *
 * 方法二: bfs, 好好背模板吧。
 * 1. 用bfs求最短路
 * 2. path[]记录路径 压入堆栈 逆序输出即为踩过的鳄鱼
 * 3. 题目要求 如果有多条最短路径相同 那么输出第一跳最小的那条路径 （在bfs中将第一跳能跳的所有节点按距离从小到大一次入队即可）
 * 4. step记录总共跳了几次 这里用last记录bfs中当前层的最后一个元素 每次last等于队列中弹出的元素 说明即将进入下一层
 * 5. 将step+1
 * */


/*
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const double D = 15.0;
double jump, cr[101][2];
int n;
bool cmp(int i, int j);
int bfs(int &v, vector<int>& path);


int main(){
    int i, v = 0, flag = 0;
    scanf("%d%lf", &n, &jump);  // 十进制浮点数
    vector<int> path(n+1, -1), s_path;  // path的长度为n+1, 默认初始值为-1, s_path的长度为0，默认初始值为0
    cr[0][0] = 0; cr[0][1] = 0;
    for(i=1; i<=n; i++)
        scanf("%lf%lf", &cr[i][0], &cr[i][1]);
    if(jump + D/2 >= 50)  // 从岛上可以直接到岸
        flag = 1;
    else
        flag = bfs(v, path);
    if(!flag)
        printf("0");
    else{
        while(v){
            s_path.push_back(v);  // 从后方将元素加进去
            v = path[v];
        }
        printf("%d\n", s_path.size() + 1);  // 总共要跳多少步
        for(i=s_path.size()-1; i>=0; i--)
            printf("%.0f %.0f\n", cr[s_path[i]][0], cr[s_path[i]][1]);
    }
    return 0;
}


bool cmp(int i, int j){  // 处理第一跳，第一个鳄鱼与原点的距离
    return pow(cr[i][0], 2) + pow(cr[i][1], 2) < pow(cr[j][0], 2) + pow(cr[j][1], 2)
}


int bfs(int &v, vector<int>& path){
    vector<int> dist(n+1, -1), first(n+1);  // dist长度为n+1， 默认值为-1, first长度为n+1
    queue<int> q;
    double firstdis;
    int flag = 0, i;
    dist[v] = 0;
    for(i=0; i<n+1; i++)
        first[i] = i;
    //多条路径相同时输出第一跳距离最小,则第一跳的节点入队列之前先从小到大排队
    sort(first.begin(), first.end(), cmp);
    for(i=1; i<n+1; i++){
        v = first[i];
        firstdis = sqrt(pow(cr[v][0], 2) + pow(cr[v][1], 2));
        if(firstdis>D/2 && firstdis<=jump+D/2){
            q.push(v);
            dist[v] = 1;
            path[v] = 0;
        }
    }
    while(!q.empty()){
        v = q.front();
        q.pop();
        if ((fabs(cr[v][0]) + jump >= 50 || fabs(cr[v][1]) + jump >= 50)){  // fabs求浮点数的绝对值
            flag = 1;
            break;
        }
        else{
            for(i=1; i<n+1; i++){
                if(dist[i] == -1 && (sqrt(pow(cr[v][0] - cr[i][0], 2) + pow(cr[v][1] - cr[i][1], 2))<=jump)){
                    dist[i] = dist[v] + 1;
                    path[i] = v;
                    q.push(i);
                }
            }
        }
    }
    return flag;
}
*/
/*
 *
 * */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>  // 方便调用sort函数
using namespace std;


struct Point{
    int x, y;  // 鳄鱼坐标
    double distance;  // 鳄鱼坐标距离原点的距离
};
#define MinLen 42.5


double dis(Point a, Point b){  // 求两个点之间的距离，方便判断两个点之间的距离是否小于跳跃距离
    return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
}


bool cmp(const Point &a, const Point &b){
    return a.distance < b.distance;
}


void firstJump(vector<int> &firstJumpIndex, vector<Point> &allPoint, int N, int D){
    sort(allPoint.begin(), allPoint.end(), cmp);  // 对距离进行升序排序

    for(int i=0; i<N; i++){
        if(allPoint[i].distance <= D+7.5)  // firstJumpIndex里存储符合要求的第一跳的点编号
            firstJumpIndex.push_back(i);
        else
            break;   // 因为已经排序过，所以只要不符合条件就退出
    }
}


int isBorder(vector<Point> &allPoint, int v, int D){  // 判断从该点是否能够跳到岸上
    if(50-abs(allPoint[v].x)<=D || 50-abs(allPoint[v].y)<=D)
        return 1;
    else
        return 0;
}


void Print(int *path, int x, vector<Point> &allPoint){
    if(path[x]!=-1)
        Print(path, path[x], allPoint);
    cout<<allPoint[x].x<<" "<<allPoint[x].y<<endl;
}


void bfs(int v, vector<Point> &allPoint, int N, int D){
    int *path = new int[N];  // 存储路径，path里存储的每个值代表父结点
    for(int i=0; i<N; i++){
        path[i] = -1;  // 初始为-1，表示无父结点
    }
    int *dist = new int[N];
    for(int i=0; i<N; i++){
        if(i==v)
            dist[i] = 1;  // 因为v是第一跳的结点，所以不可能是最后跳出的那个鳄鱼点，所以跳跃的次数一定是1
        else
            dist[i] = 0;  // 不是第一跳的结点，有可能是终结点
    }
    queue<int> Q;

    int x, flag = 0;
    Q.push(v);
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        if(isBorder(allPoint, x, D)){  // 判断从该点能否跳到岸上
            flag = 1;
            break;
        }
        else{
            for(int i=0; i<N; i++){
                if(dist[i]==0 && dis(allPoint[x], allPoint[i])<=D){
                    path[i] = x;
                    dist[i] = dist[x]+1;  // 根据之前上一层的结点跳的步数来决定下一层节点跳的步数
                    Q.push(i);
                }
            }
        }
    }

    if(flag){
        cout<<dist[x]+1<<endl;
        Print(path, x, allPoint);
        exit(0);
    }
}


void initData(vector<Point> &allPoint, int N){  // 读入数据
    Point temp;
    int x, y;
    double d;
    for(int i=0; i<N; i++){
        cin>>x>>y;
        d=sqrt(x*x+y*y);
        if (max(abs(x), abs(y)) >= 50 || max(abs(x), abs(y)) < 7.5)	//此处是为了淘汰掉那些不在水中的点；
            continue;
        temp.x = x;
        temp.y = y;
        temp.distance = d;
        allPoint.push_back(temp);
    }
}


int main(){
    vector<Point> allPoint;
    vector<int> firstJumpIndex;  // 用来存储第一跳符合要求的点的编号
    int N, tN, D;  // N个鳄鱼坐标点， D代表007最大的跳跃距离
    cin>>tN>>D;
    initData(allPoint, tN);
    N = allPoint.size();  // 这里用tN和N两个变量的原因是会通过initData函数剔除一部分点，在岛上的鳄鱼，超过50界限的鳄鱼，所以实际的N有可能比tN要小的
    cout<<"#######"<<endl;
    cout<<N<<endl;
    cout<<"#######"<<endl;
    firstJump(firstJumpIndex, allPoint, N, D);  // 处理第一跳

    if(D>=42.5)
        cout<<1<<endl;
    else{
        for(int i=0; i<firstJumpIndex.size(); i++)  // 第一跳的每点bfs
            bfs(i, allPoint, N, D);
        cout<<0<<endl;
    }

    return 0;
}