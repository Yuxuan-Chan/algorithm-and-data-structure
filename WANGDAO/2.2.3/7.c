//
// Created by zhang on 2018/9/17.
//
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100
typedef int ElementType;
typedef struct {
    ElementType data[MaxSize];
    int length;
}sqList;


bool merge(sqList L1, sqList L2, sqList L3){
    if (L1.length + L2.length > L3.length){
        return false;
    }
    int i, j, k;
    i = j = k = 0;
    while (i<L1.length&&j<L2.length){
        if(L1.data[i]<=L2.data[j]){
            L3.data[k++] = L1.data[i++];
        }else{
            L3.data[k++] = L2.data[j++];
        }
    }
    while(i<L1.length){
        L3.data[k++] = L1.data[i++];
    }
    while(j<L2.length){
        L3.data[k++] = L2.data[j++];
    }
    L3.length = k;
    return true;
}