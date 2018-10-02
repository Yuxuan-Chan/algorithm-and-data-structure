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


bool delete(sqList L, int s, int t){
    if (L.length==0||s>=t)
        return false;
    int k = 0;
    for (int i=0; i<L.length; i++){
        if(L.data[i]<s||L.data[i]>t){
            L.data[k] = L.data[i];
            k++;
        }
    }
    L.length = k;
    printf("%d\n", L.length);
    for (int i=0; i<L.length; i++){
        printf("%d\n", L.data[i]);
    }
    return true;
}

int main(){
    sqList L;
    L.length = 3;
    L.data[0] = 0;
    L.data[1] = 1;
    L.data[2] = 2;

    delete(L, 0, 1);
}