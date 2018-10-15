//
// Created by zhang on 2018/10/15.
//
/* 输入
 * 第一行是两个正整数N，表示用户数，L，给定的间接关注者的层数
 * 然后是N行，每一行的格式是
 * M[i] user_list[i]
 * 其中M[i]表示用户i的关注数。user_list[i]是具体关注列表， 共M[i]个。
 * 最后给出K，和K个数字，表示用户ID，要求对每个用户ID进行查询，查询其L层粉丝数。
 *
 * 输出
 * 对于每个ID，输出其L层共多少个粉丝。
 * Sample Input:
 * 7 3
 * 3 2 3 4
 * 0
 * 2 5 6
 * 2 3 1
 * 2 3 4
 * 1 4
 * 1 5
 * 2 2 6  // 要求id为2和id为6的最大潜在转发数为多少？
 *
 * Sample Output:
 * 4
 * 5
 *
 * 题目含义其实是这样的:
 * id为1关注了3个人，id分别是2，3，4
 * id为2关注了0个人
 * id为3关注了2个人，id分别是5，6
 * id为4关注了2个人，id分别是3，1
 * id为5关注了2个人，id分别是3，4
 * id为6关注了1个人，id分别是4
 * id为7关注了1个人，id分别是5
 *
 * 然后最后一行2 2 6代表首先给定了2个数，id分别是2和6，求他们在最大转发层数3的限制下，可以最多转发多少人
 * 那么这个计算方法也是有技巧的，可以首先计算直接关注的id是什么，再计算间接关注的id，加上层数限制
 * */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define MaxSize 1001
int n, l, m, k;
struct node{
    int id, layer;
};
vector<vector<int> > v;  // 这里一定要注意，不要把>>写在一起，c++会认为是输入符号


int BFS(int node){
    bool visited[MaxSize] = {false};
    queue<node> q;
    q.push(node);
    visited[node] = true;
    int count = 0;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        int topid = top.id;
        for(int i=0; i<v[topid].size(); i++){
            int nextid = v[topid][i];
            if(!visited[nextid]&&top.layer<l){
                node next = {nextid, top.layer++};
                count++;
                q.push(next);
                visited[next.id] = true;
            }
        }
    }

    return count;
}

int main(){
    scanf("%d %d", &n, &l);
    v.resize(n+1);
    for(int i=1; i<=n; i++){
        scanf("%d", &m);
        for(int j=0; j<m; j++){
            int temp;
            scanf("%d", &temp);
            v[temp].push_back(i);
        }
    }
    scanf("%d", &k);
    int tid;
    for(int i=0; i<k; i++){
        scanf("%d", &tid);
        node tnode = {tid, 0};
        printf("%d\n", bfs(tnode));
    }

    return 0;
}