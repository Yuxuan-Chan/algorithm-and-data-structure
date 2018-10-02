//
// Created by zhang on 2018/9/19.
//
#include <stdio.h>
#define MaxSize 100
typedef int ElementType;
typedef struct{
    ElementType data[MaxSize];
    int length;
}sqList;

// 1 2 3 4 5 (m = 1, 2, 3 n = 4, 5) => 1 2 3 4 5 => 4 5 3 1 2 => 4 5 1 2 3 (将第一个位置的3保存到一个变量，同时将后面的1 2向前移动一个单位，空出最后一个位置，将3填充到最后一个位置)
// 1 2 3 4 5 (m = 1, 2 n = 3, 4, 5) => 3 4 1 2 5 => 3 4 5 1 2
void reorder(sqList L, int m, int n){
    if (m < n){
        int count = 0;
        while (count!=m){
            int temp;
            temp = L.data[count];
            L.data[count] = L.data[n];
            L.data[n] = temp;
            n++;
            count++;
        }
    }
    else if (m > n){
        int count = 0;
        while (count!=n){
            int temp;
            temp = L.data[count];
            L.data[count] = L.data[L.length-count];
            L.data[L.length-count] = temp;
            count++;
        }
        int suppose_last_element = L.data[m];
        for(int i=m; i<L.length; i++){
            L.data[i-1] = L.data[i];
        }
        L.data[L.length-1] = suppose_last_element;
    }
    else{
        int start = 0;
        for(;n<L.length;n++){
            int temp;
            temp = L.data[start];
            L.data[start] = L.data[n];
            L.data[n] = temp;
            start++;
        }
    }

}
