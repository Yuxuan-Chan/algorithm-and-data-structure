//
// Created by zhang on 2018/9/13.
//
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100
typedef int ElementType;
typedef struct {
    ElementType data[MaxSize];
    int length;
}sqList;



bool Delete_Same(sqList *ptrS){
    if (ptrS->length==0)
        return false;
    int i, j;
    for(i=0, j=1; j<ptrS->length; j++)
        if(ptrS->data[i]!=ptrS->data[j])
            ptrS->data[++i] = ptrS->data[j];
    ptrS->length = i+1;
    return true;
}