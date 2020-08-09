/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-09-17.12.53
* Description : 查找倒数第K个节点
*/
#include<stdio.h>

/***
 * 节点声明】
 **/
typedef int ElemType;
typedef struct LNode {
    ElemType val;
    struct LNode *next;
}LNode, *LinkList;

/***
 * 查找倒数第K个节点
 **/
int search_k(LinkList head, int k);

int main(){

    // [test]
    // 头结点；
    LinkList head = (LinkList)malloc(sizeof(LNode));
    LinkList p = head;

    int i = 0;
    p->val = 0;

    // 填充；
    while(i < 10){
        p->next = (LinkList)malloc(sizeof(LNode));
        p = p->next;

        p->val = i * 10;

        i++;
    }

    // 尾结点的next赋值为NULL；
    p->next = NULL;

    search_k(head, 3);

    printf("%d\n", head->val);

    // 遍历节点；
    p = head;
    while(p != NULL){
        printf("%d\n", p->val);
        p = p->next;
    }

    printf("%d\n", head->val);
    return 0;
}

int search_k(LinkList head, int k){
    LinkList p = head->next, q = head->next;

    int count = 0;

    while(p != NULL){

        // 记录节点个数，当节点个数等于k时停止记录;
        if(count < k){
            count++;

        // 当节点个数大于等于k时开始向后移动q;
        }else{
            q = q->next;
        }

        // 一直移动p直到p为NULL；
        p = p->next;
    }

    // 判断是否总节点数小于k个；
    if(count < k){
        printf("The number of node is less than the value of k!\n");
        return 0;
    }else{
        printf("The value is: %d\n", q->val);
        return 1;
    }
}
