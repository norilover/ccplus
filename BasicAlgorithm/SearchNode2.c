/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-09-18.23.35
* Description : 查找链表共同后缀的第一个节点
*/
#include<stdio.h>
/***
 * 节点声明】
 **/
 typedef char ElemType;
typedef struct Node{
    ElemType val;
    struct Node *next;
}Node;

/***
 * 获取链表长度
 **/
int getListLen(Node *head);

/***
 * 查找链表共同后缀的第一个节点
 **/
Node *searchFirstSuffixNode(Node *p, Node *q);

int main(){
    // [TEST]
    // 设置head1链表的部分节点；
    Node *head1 = (Node *)malloc(sizeof(Node));
    Node *p = head1;
    p->val = '0';
    ElemType c[] = {'s','t','a','n','d'};
    int i = -1;
    while(++i < 5){
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        p->val = c[i];
    }

    // 设置head2链表的部分节点；
    Node *head2 = (Node *)malloc(sizeof(Node));
    Node *q = head2;
    q->val = '0';

    ElemType cc[] = {'l','y'};
    i = -1;
    while(++i < 2){
        q->next = (Node *)malloc(sizeof(Node));
        q = q->next;
        q->val = cc[i];
    }

    // 设置两个链表的共同后缀；
    i = -1;
    ElemType ccc[] = {'i','n','g'};
    while(++i < 3){
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        p->val = ccc[i];

        q->next = p;
        q = q->next;
    }

    // 尾部赋值为NULL；
    p->next = NULL;
    q->next = NULL;

    // 遍历节点中的元素；
    p = head1->next;//, *q = q->next;
    printf("head1:\n");
    while(p != NULL){
        printf("%c\n", p->val);
        p =p->next;
    }

    q = head2->next;
    printf("head2:\n");
    while(q != NULL){
        printf("%c\n", q->val);
        q = q->next;
    }

    // 获取共同后缀的第一个节点；
    Node *target = searchFirstSuffixNode(head1, head2);
    printf("The Node is: \n%c", target->val);

    return 0;
}

int getListLen(Node *head){
    int len = 0;

    while(head != NULL){
        len++;
        head = head->next;
    }

    return len;
}

Node *searchFirstSuffixNode(Node *head1, Node *head2){
    Node *p = head1, *q = head2;

    // 获取链表长度；
    int m = getListLen(p);
    int n = getListLen(q);

    // 跳过较长链表的多余部分；
    for (; m > n; m--){
        p = p->next;
    }
    for(; m < n; n--){
        q = q->next;
    }

    // 开始查找共同前缀节点；
    while(p != NULL && p != q){
        p = p->next;
        q = q->next;
    }

    return p;
}
