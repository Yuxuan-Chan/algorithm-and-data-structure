//
// Created by zhang on 2018/9/16.
//  http://www.cnblogs.com/llhthinker/p/4748676.html
//  https://www.cnblogs.com/ranjiewen/p/6629589.html
//  https://blog.csdn.net/shinanhualiu/article/details/49253499
//#include <stdio.h>
//#define MaxTree 10
//#define Null -1
//typedef struct{
//    int Data;
//    int Left;
//    int Right;
//}TreeNode;
//TreeNode node[MaxTree];
//TreeNode Queue[MaxTree];
//int N, check[MaxTree];
//int first = -1, last = -1;
//
//
//int BuildTree(){
//    int Root=Null, i;
//    char cl, cr;
//    scanf("%d", &N);
//    if (N){
//        for(i=0; i<N; i++)
//            check[i] = 0;
//        for(i=0; i<N; i++){
//            node[i].Data = i;
//            scanf("\n%c %c", &cl, &cr);
//            if (cl != '-'){
//                node[i].Left = cl - '0';
//                check[node[i].Left] = 1;
//            }else{
//                node[i].Left = Null;
//            }
//            if (cr != '-'){
//                node[i].Right = cr - '0';
//                check[node[i].Right] = 1;
//            }else{
//                node[i].Right = Null;
//            }
//        }
//        for(i=0;i<N;i++)
//            if(!check[i])
//                break;
//        Root = i;
//    }
//    return Root;
//}
//
//
//void push(TreeNode treeNode){
//    Queue[++last] = treeNode;
//}
//
//
//TreeNode pop(){
//    return Queue[++first];
//}
//
//
//void findLeaves(int root, int n){
//    int leaves[MaxTree];
//    int k = 0;
//    push(node[root]);
//    for (int i=0; i<n; i++){
//        TreeNode tn = pop();
//        // 左孩子和右孩子都不存在时，将叶节点的值保存到数组中
//        if (tn.Left == -1 && tn.Right == -1)
//            leaves[k++] = tn.Data;
//        if (tn.Left != -1)
//            push(node[tn.Left]);
//        if (tn.Right != -1)
//            push(node[tn.Right]);
//    }
//    for (int i=0; i<k-1; i++)
//        printf("%d ", leaves[i]);
//    printf("%d\n", leaves[k-1]);
//}
//
//
//
//int main(){
//    int root = BuildTree();
//    findLeaves(root, N);
//
//    return 0;
//}
