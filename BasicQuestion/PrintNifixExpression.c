/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-23-09.55.25
* Description : 打印中缀表达式，给一个表达式树（二叉树），求其对应的中缀表达式，并输出
*   eg.
*     表达式树：
*              *
*          +       *
*        a   b   c   -
*                       d
*     对应的中缀表达式：
*          (a + b) * (c * (-d))
*/
#include<stdio.h>
/***
 * 二叉树节点定义
 **/
typedef struct node {
    char data;
    struct node *left;
    struct node *right;
}tn;

/***
 * 输出中缀表达式
 **/
void getLNRExp(tn *head);

 /***
 * 中序遍历
 **/
void traverseLNR(tn *head, int depth);

/***
 * 中序遍历打印树中元素
 **/
void printLNRTree(tn* head);

int main(){

    // 头结点
    tn *head = (tn *)malloc(sizeof(tn));
    head->data =  '*';

    // 左子树
    tn *pLeft = (tn *)malloc(sizeof(tn));
    pLeft->data = '+';
    head->left = pLeft;

    pLeft->left = (tn *)malloc(sizeof(tn));
    pLeft->left->data = 'a';
    pLeft->left->left = NULL;
    pLeft->left->right = NULL;

    pLeft->right = (tn *)malloc(sizeof(tn));
    pLeft->right->data = 'b';
    pLeft->right->left = NULL;
    pLeft->right->right = NULL;

    // 右子树
    tn *pRight = (tn *)malloc(sizeof(tn));
    pRight->data = '*';
    head->right = pRight;
    pRight->left = (tn *)malloc(sizeof(tn));
    pRight->left->data = 'c';
    pRight->left->left = NULL;
    pRight->left->right = NULL;

    pRight->right = (tn *)malloc(sizeof(tn));
    pRight->right->data = '-';

    pRight = pRight->right;
    pRight->left = NULL;
    pRight->right = (tn *)malloc(sizeof(tn));
    pRight->right->data = 'd';
    pRight->right->left = NULL;
    pRight->right->right = NULL;

    // 中序输出节点值
    printLNRTree(head);

    // 输出中缀表达式
    getLNRExp(head);

    return 0;

}

/***
 * 输出中缀表达式
 **/
void getLNRExp(tn *head) {
    printf("Nifix Expression is: ");
    traverseLNR(head, 1);

    return ;
}

 /***
 * 中序遍历
 **/
void traverseLNR(tn *head, int depth) {

    if(head == NULL) {
        return ;
    }

    if(head->left == NULL && head->right == NULL) {
        printf("%c", head->data);
    }else{
        if(depth > 1) {
            printf("(");
        }

        traverseLNR(head->left, depth + 1);

        printf("%c", head->data);

        traverseLNR(head->right, depth + 1);

        if(depth > 1) {
            printf(")");
        }
    }
}

/***
 * 中序遍历打印树中元素
 **/
void printLNRTree(tn* head) {
    if(head == NULL){
        return ;
    }

    printLNRTree(head->left);

    printf("The element is: %c \n", head->data);

    printLNRTree(head->right);
}

