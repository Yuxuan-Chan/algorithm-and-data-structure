//
// Created by zhang on 2018/9/13.
//
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MaxSize 100
//typedef int ElementType;
//typedef struct{
//    ElementType data[MaxSize];
//    int length;
//}sqList;
//
//
//bool delete(sqList L, int s, int t){
//    int i, j;
//    if (s > t || L.length == 0)
//        return false;
//    for (i=0; i<L.length&&L.data[i]<s;i++);
//    if (i >= L.length)
//        return false;
//    for (j=i; j<L.length&&L.data[j]<=t;j++);
//    for(;j<L.length;i++,j++)
//        L.data[i] = L.data[j];
//    L.length = i;
//    return true;
//}