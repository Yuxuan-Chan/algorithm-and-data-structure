//
// Created by zhang on 2018/9/13.
// https://blog.csdn.net/yeternity/article/details/72794956
// 题意是满足K个结点的一段链表就要逆转，而不满K个结点的不需要逆转（比如有10个结点的链表，K为4，那么分为两部分：0123，4567需要逆转，89只有2个不逆转）
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//#define MaxSize 100000
//struct node{
//    int Data;
//    int Next;
//}list[MaxSize];
//
//
//int reverse(int head, int reverseNum){
//    int prev, curr, next;  // New Old Tmp
//    int count = 1;
//    prev = head;  // New = head;
//    curr = list[prev].Next;  // Old = list[New].Next
//    while(count!=reverseNum){
//        next = list[curr].Next; // Temp = list[Old].Next
//        list[curr].Next = prev; // 反转  list[Old].Next = New
//        prev = curr;  // New = Old
//        curr = next;  // Old = Tmp
//        count++;
//    }
//    list[head].Next = curr;  // list[head].Next = Old
//    return prev;  // New
//}
//
//bool needReverse(int head, int reverseNum){
//    int i;
//    for (i=1; list[head].Next!=-1; head=list[head].Next){
//        i++;
//        if (i==reverseNum)
//            return true;
//    }
//    return false;
//}
//
//
//int reverseAll(int head, int reverseNum){
//    int unreversedHead = head;
//    int listHead;
//    int tempTail;
//
//    if (needReverse(unreversedHead, reverseNum)){
//        listHead = reverse(unreversedHead, reverseNum); // 新的表头，如果总的结点数为10，翻转数为4，那么有两段需要翻转，那么listHead就是新的头节点(第4个结点)
//        tempTail = unreversedHead;  // 第1个结点，现在变成了尾节点
//        unreversedHead = list[tempTail].Next;  // 第5个节点，现在是什么都没做的第1个节点(变成了第4个), 接下来要从这个点开始翻转
//    }
//    else
//        return head;
//
//    while(needReverse(unreversedHead, reverseNum)){
//        list[tempTail].Next = reverse(unreversedHead, reverseNum);  // 现在理清一下变量代表的节点位置，按原先什么都没进行改变时的节点来表示，tempTail(第一个节点)， listHead(第四个节点), unreversedHead(第五个节点), 那么在调用reverse函数后，由于逆转的是5-8这4个节点，返回的节点是第8个节点
//        tempTail = unreversedHead; // 现在尾巴节点是第5个节点了，之前在上面的赋值当中可以知道，unreversedHead就是第5个节点
//        unreversedHead = list[tempTail].Next; // 由于第5个节点变成了尾巴节点，它现在指向的是第9个节点，这是下一段要翻转的开头
//    }
//    return listHead;
//}
//
//void printList(int head){
//    int temp = head;
//    while(list[temp].Next!=-1){
//        printf("%05d %d %05d\n", temp, list[temp].Data, list[temp].Next);
//        temp = list[temp].Next;
//    }
//    printf("%05d %d %d\n", temp, list[temp].Data, list[temp].Next);
//}
//
//
//int main(){
//    int startAddress, totalNum, reverseNum;
//    int position;
//    scanf("%d %d %d", &startAddress, &totalNum, &reverseNum);
//    for (int i=0; i<totalNum; i++){
//        scanf("%d %d %d", &position, &list[position].Data, &list[position].Next);
//    }
//
//    printList(reverseAll(startAddress, reverseNum));
//    system("pause");
//    return 0;
//}