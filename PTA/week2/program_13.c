//
// Created by zhang on 2018/10/1.
//
//#include <stdio.h>
//typedef int ElementType;
//typedef struct{
//    ElementType Data;
//    int Parent;
//} SetType;
//
//
//int Find(SetType S[], ElementType X)
//{
//    for(int i=0; i<MaxSize&&S[i].Data!=X; i++);
//    if (i>=MaxSize)
//        return -1;
//    for(;S[i].Parent>=0; i=S[i].Parent);
//    return i;
//}
//
//
//void Union(SetType S[], ElementType X1, ElementType X2)
//{
//    int Root1, Root2;
//    Root1 = Find(S, X1);
//    Root2 = Find(S, X2);
//    if(Root1 != Root2)
//        S[Root2].Parent = Root1;
//}
// 题目大意：判断两台电脑是否连通，并判断电脑间是否相互连通，否则输出最大连通数目
// 可以通过集合来解决这道题。利用判断两台电脑是否在同一集合里，若是则连通，否则不连通。
// https://www.cnblogs.com/kuotian/p/5351987.html
// https://blog.csdn.net/qq_37754288/article/details/78473366
// https://blog.csdn.net/m0_37286282/article/details/72081765
#include <stdio.h>
#define MaxN 10001  // 集合最大元素个数
typedef int ElementType;  // 默认元素可以用非负正数表示
typedef int SetName;  // 默认用根节点下标作为集合名称
ElementType SetType[MaxN];  // 假设集合元素下标从1开始


void Union(ElementType S[], SetName Root1, SetName Root2);
SetName Find(ElementType S[], ElementType X);


void Union(ElementType S[], SetName Root1, SetName Root2){
    if (S[Root1] < S[Root2]){  // 所以数组下标是代表元素，数组的元素代表的是集合元素个数
        S[Root1] += S[Root2];  // 这里的思想其实就是用负数的绝对值代表总的节点数，当并入的时候节点总数变了
        S[Root2] = Root1;  // 所以S[Root1] < S[Root2] -7 < -3 其实是Root1是节点数比较多的一方
        // Root1是根
    }
    else{  // Root2是根
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
}


SetName Find(ElementType S[], ElementType X){
    // 默认集合元素全部初始化为-1
    if (S[X] < 0)  // 找到集合的根
        return X;
    else
        return S[X] = Find(S, S[X]);
}


int main(){
    int N;
    int computerA, computerB;
    scanf("%d", &N);
    for(int i=0; i<N+1; i++)
        SetType[i] = -1;
    char operation;
    scanf("%c", &operation);
    while(operation != 'S'){
        if(operation == 'I'){
            scanf("%d %d", &computerA, &computerB);
            Union(SetType, Find(SetType, computerA), Find(SetType, computerB));
        }
        else if(operation == 'C'){
            scanf("%d %d", &computerA, &computerB);
            if (Find(SetType, computerA) == Find(SetType, computerB)){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
        scanf("%c", &operation);
    }
    int components = 0;
    for(int i=1; i<N+1; i++){
        if (SetType[i] < 0){
            components++;
        }
    }
    if(components==1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", components);
    return 0;
}

// 主要思路还是像专栏里写的那样，通过用根的负数的绝对值来代表树中一共有多少个节点
// 合并的时候将小的合并到大的里面即可，根的结点总数要更新，小的数的根节点也指向了大的树的根