//
// Created by zhang on 2018/9/14.
//
//#include <stdio.h>
//#include <stdbool.h>
//#define MAXSIZE 1000
//
//typedef struct {
//    int data[MAXSIZE];
//    int top;
//    int capacity;
//}SqStack;
//
//
//int InitStack(SqStack *s, int capacity){
//    s->top = -1;
//    s->capacity = capacity;
//    return 0;
//}
//
//
//int push(SqStack *s, int e){
//    if (s->top == s->capacity -1){
//        return -1;
//    }else{
//        s->data[s->top+1] = e;
//        s->top++;
//        return 0;
//    }
//}
//
//
//int pop(SqStack *s){
//    if (s->top == -1){
//        return -1;
//    }else{
//        int e;
//        e = s->data[s->top];
//        s->top -= 1;
//        return e;
//    }
//}
//
//
//bool check(SqStack *s, int *array, const int n){
//    int result[n];
//    int * const arrayEnd = array + n;
//    if (array[0] > 5){
//        return false;
//    }else{
//
//    }
//    for (; array < arrayEnd; array++){
//        if
//    }
//}
//
//
//void test(int *array, const int n){
//    int * const arrayEnd = array + n;
//    for (; array < arrayEnd; array++){
//        printf("%d\n", *array);
//    }
////    printf("%d", array[0]);
//}
//
//int main(){
////    int array[3] = {10, 100, 1000};
////    test(array, 3);
////    printf("%d %d %d", array[0], array[1], array[2]);
//
//    SqStack s;
//    int m, n, k;
//    scanf("%d %d %d", &m, &n, &k);
//    InitStack(&s, m);
//    int element;
//    int array[n];
//    for (int i=0; i<k; i++){
//        for (int j=0; j<n; j++){
//            scanf("%d", &element);
//            array[i] = element;
//        }
//        check(&s, array);
//    }
//
//
////    push(&s, 1);
////    push(&s, 2);
////    push(&s, 3);
////    push(&s, 4);
////    push(&s, 5);
////    push(&s, 6);
////    printf("%d\n", s.top);
////    int res = pop(&s);
////    printf("%d", res);
//    return 0;
//}

/*
 * void myFunction(int *param){
 *
 * }
 *
 *
 * void myFunction(int param[10]){
 *
 * }
 *
 * void myFunction(int param[]){
 *
 * }
 * */