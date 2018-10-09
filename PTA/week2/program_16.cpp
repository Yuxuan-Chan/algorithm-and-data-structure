//
// Created by zhang on 2018/10/9.
//

/*
// 确定图的结点和边，鳄鱼的头是结点，岸边也是图里面的结点
// 图的遍历问题dfs, bfs, 只要发现一条鳄鱼跟岸边是有边的，就是可以活命的
// 007的第一跳跟其它的跳跃是不一样的，一个明显的区别是，第一跳的半径是不一样的，所以不方便把第一跳也放在递归里面一起处理，因为我们递归的时候基本上是一个重复的同样的过程，所以希望跳跃的半径都是一样的，于是孤岛其实应该被作为一个特殊的结点来处理
void ListComponents(Graph G){
    for(each V in G)
        if(!visited[V]){
            DFS(V);
        }
}


void Save007(Graph G){
    for(each V in G){
        if(!visited[V] && FirstJump(V)){
            answer = DFS(V);  // 在这个故事里面，visited[V]在这里面是True,就意味着007已经在这条鳄鱼的头上踩过一脚了，如果他还没有踩过一脚，那么我们应该去做DFS,就是一脚踩上去，除此之外，我们还要做一个什么判断呢？其实我们的第一跳不仅是看这个鳄鱼有没有被踩过，而且要看007能不能够得着，所以这个条件里面还要加一个FirstJump，这个函数的功能就是把V给到这个函数里，它要能告诉我说007的第一跳从孤岛跳到这个V上面，有没有可能，如果这个函数返回的结果是真的话，同时这条鳄鱼又没有被踩过的话，那么我们就跳上去，那基本上到这里我们的问题就解决了，稍微有一点细节就是，我们不仅要踩一遍鳄鱼，还得告诉007，yes或者no,所以DFS在里面，不能在像以前那样是一个void函数，必须要返回一个结果
            if (answer = YES)
                break;
        }
    }
    if (answer == YES)  // 我们把返回的结果记在answer里面，就是这个答案，如果这个答案是yes,那么我不要接着往下做了，直接就跳出来，跳出来，如果这个answer是yes,我们就告诉它是yes,如果到所有的循环都做完了，始终都没有得到一个yes的答案的话，那么它就没救了，你要告诉它no
        output("Yes")
    else
        output("No")
}

// 对DFS函数进行改造
int DFS(Vertex V){
    visited[V] = true;
    if(IsSafe(V))  // 首先007一脚踩上去了(visited[V]=true)，之后他要做的一件事情，放眼一望，他是要急着找下一条鳄鱼吗？肯定不是的，他最关心的是能不能从这条鳄鱼跳到岸上去
        answer = YES;
    // 所以在找下一条鳄鱼之前，我们先要有一个函数IsSafe,IsSafe这个函数它要做的事情是什么呢？我把V也就是这条鳄鱼的坐标传给你，你要告诉它说从这个地方能不能直接跳上岸，如果能，返回真，不能，返回假，如果这个IsSafe函数，返回的是真的话，那么很好，它不用往下跳了，它可以直接answer等于yes,然后就return answer它就回去了，如果这条鳄鱼不行，那么只好去看看其它的鳄鱼，当然在检查其它鳄鱼，递归的时候，我们要返回一个answer,如果这个answer在任何时候是等于yes的话，我们就break,跳出来直接返回这个answer
    else
        for(each W in G){
            if(!visited[W] && Jump(V, W)){  // 如果这条鳄鱼还没有踩过，并且我们可以从V跳到W上面，所以这里有一个Jump函数，Jump函数要解决的就是算一下V和W之间的距离，是不是小于007可以跳跃的最大距离，如果可以的话，返回真，那就意味着它真的可以跳上去，在这里面我们扫描的是G里面的每一个W,如果可以跳上去，就意味着它有边，就意味着W是V的邻接点，如果它没有被访问过的话，我们进行DFS
                answer = DFS(W);
                if (answer == YES)
                    break;
            }
        }
    return answer;
}
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define MinLen 42.5
struct Point{
    int x;
    int y;
    bool visited;
};
Point 0;
int N, D;
vector<Point> S;


double distance(Point a, Point b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}


void search(int i){
    S[i].visited = true;
    if ((50-abs(S[i].x))<=D || (50-abs(S[i].y))<=D){
        cout << "Yes" << endl;
        exit(0);
    }
    else{
        for(int j=0; j<N; j++){
            if(!s[j].visited&&distance(s[i], s[j])<=D){
                search(j);
            }
        }
    }
}


int main(){
    0.x = 0;
    0.y = 0;
    0.visited = false;
    vector<int> firstJump = {0};
    cin>>N>>D;
    if(D >= MinLen){
        cout<<"Yes"<<endl;
        return 0;
    }
    Point Crocodile;
    for(int i=0; i<N; i++){
        cin >> Crocodile.x >> Crocodile.y >> endl;
        Crocodile.visited = false;
        S.push_back(Crocodile);
    }
    for(int i=0; i<N; i++){
        if(distance(0, S[i]) <= (D+7.5)){
            firstJump.push_back(i);
        }
    }
    if(firstJump.empty()){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0; i<firstJump.size(); i++)
        search(firstJump[i]);
    cout << "No" << endl;
    return 0;
}
