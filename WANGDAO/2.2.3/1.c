//
// Created by zhang on 2018/9/12.
//
//#include <stdio.h>
//#include <stdbool.h>
//
//#define MaxSize 100
//typedef int ElementType;
//typedef struct {
//    ElementType data[MaxSize];
//    int length;
//}sqList;
//
//
//bool deleteMinimum(sqList L, ElementType value){
//    if (L.length == 0){
//        return false;
//    }
//    value = L.data[0];
//    int index = 0;
//    for(int i=0; i<L.length; i++){
//        if(L.data[i] < value){
//            value = L.data[i];
//            index = i;
//        }
//    }
//    L.data[index] = L.data[L.length-1];
//    L.length--;
////    printf("%d\n", L.length);
////    for (int i=0; i<3; i++){
////        printf("%d\n", L.data[i]);
////    }
//    return true;
//}
//
//
//int main(){
//    sqList input;
//    input.data[0] = 1;
//    input.data[1] = 2;
//    input.data[2] = 3;
//    input.length = 3;
//    ElementType val=0;
//    bool res = deleteMinimum(input, val);
//    printf("%d\n", input.length);  // 这里函数内进行了浅复制，所以这里测不出
//    return 0;
//}