//
// Created by zhang on 2018/9/12.
//
//#include <stdio.h>
//#define MaxSize 100
//typedef int ElementType;
//typedef struct {
//    ElementType data[MaxSize];
//    int length;
//}sqList;
//
//
//void reverse(sqList L){
//    ElementType temp=0;
//    for(int i=0; i<L.length/2; i++){
//        temp = L.data[i];
//        L.data[i] = L.data[L.length-i-1];
//        L.data[L.length-i-1] = temp;
//    }
//
//    for(int i=0; i<L.length; i++){
//        printf("%d\n", L.data[i]);
//    }
//}
//
//
//int main(){
//    sqList L;
//    L.length = 3;
//    L.data[0] = 0;
//    L.data[1] = 1;
//    L.data[2] = 2;
//    reverse(L);
//
//    return 0;
//}
