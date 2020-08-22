/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-22-17.36.10
* Description : WPL(Weight Path Length) 求二叉树的带权路径长度
*   带权路径长度: 指 根节点 到 叶子结点所经过的路径条数 乘以 该叶子节点的权重，之后再将其相加即为所求。
*/
#include<stdio.h>
/***
 * 树节点定义
 **/
 #define EleType int
 typedef struct TreeNode {
    EleType weight;
    struct TreeNode *leftChild;
    struct TreeNode *rightChild;
 }tn;

/***
 * 获取二叉树的带权路径长度
 **/
int getWPL(tn *head);

/***
 * 前序遍历计算WPL
 **/
int calWPL(tn *head, int depth);

int main() {
    // 根节点
    tn * head = (tn *)malloc(sizeof(tn));
    head->weight = 2;

    // 左子树
    tn * p = (tn *)malloc(sizeof(tn));
    p->weight = 10;
    p->leftChild = NULL;
    p->rightChild = NULL;
    head->leftChild = p;

    // 右子树
    p = (tn *)malloc(sizeof(tn));
    p->weight = 100;
    p->leftChild = NULL;
    p->rightChild = NULL;
    head->rightChild = p;

    /*
    树结构图：
         2
      10   100
    */

    int WPL = getWPL(head);

    printf("The WPL is: %d\n", WPL);

    return 0;
}

int getWPL(tn *head) {
    return calWPL(head, 0);
}

int calWPL(tn *head, int depth) {
    static int WPL = 0;

    // head指向叶子节点
    if(head->leftChild == NULL && head->rightChild == NULL){
        // 计算该节点的 带权路径 并累加
        WPL += depth * head->weight;
    }

    // 继续访问左子树
    if(head->leftChild != NULL){
        calWPL(head->leftChild, depth + 1);
    }

    // 继续访问右子树
    if(head->rightChild != NULL){
        calWPL(head->rightChild, depth + 1);
    }

    return WPL;
}



