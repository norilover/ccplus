/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-29-10.04.10
* Description : 前序遍历 查找第K个节点
*/
#include<stdio.h>


typedef char ElemType ;
int n = 1;

typedef struct TreeNode {
    ElemType val;
    struct TreeNode *left;
    struct TreeNode *right;
}tn;

/***
 * 输出数组元素
 **/
printTNValue(tn *head){

    if(head != NULL){
        printf("The element is： %c\n", head->val);

        printTNValue(head->left);
        printTNValue(head->right);
    }

    return 0;
}

/***
 * 循环赋值
 **/
givenTreeNodeValue(tn *head, int len, int size){
    if(len > size){
        head->left = NULL;
        head->right = NULL;
        return 0;
    }

    head->left = (tn *)malloc(sizeof(tn));
    head->left->val = (char)(len + 'a');

    head->right = (tn *)malloc(sizeof(tn));
    head->right->val = (char)(len + 'A');

    givenTreeNodeValue(head->left, ++len, size);
    givenTreeNodeValue(head->right, ++len, size);

    return 0;
}


/***
 * 前序遍历数组
 **/
tn *preNode(tn *head, const int k){
    // 如果到达叶子节点返回@，作为标记
    if(head == NULL)
        return '@';

    if(n == k)
        return head->val;
    n++;

    char ch = preNode(head->left, k);
    if(ch != '@')
        return ch;
    else{
        ch = preNode(head->right, k);
        return ch;
    }
}

int main(){

    tn *head = (tn *)malloc(sizeof(tn));

    // 生成测试树
    givenTreeNodeValue(head, 0, 5);

    // 输出元素值
    printTNValue(head);

    char result = preNode(head, 10);
    printf("The target is: %c\n", result);

    return 0;
}
