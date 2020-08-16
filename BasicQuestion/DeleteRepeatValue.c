/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-16-11.26.40
* Description : 给定一个数组，且数组中所有元素满足 |element| < n, 要求删除绝对值相等的多余节点
*/
#include<stdio.h>
#include<cstdlib>
/***
 * 节点定义
 **/
typedef struct node{
    int data;
    struct node *link;
}node;

/***
 * 数组长度
 **/
#define N 10

/***
 * 删除多余元素
 **/
void deleteRepeatValue(node *head, const int n);

int main(){

    // 头结点
    node *head = (node *)malloc(sizeof(node));
    node *p = head;

    // 设置测试元素
    p->link = (node *)malloc(sizeof(node));
    p->link->data = 3;
    p = p->link;
    p->link = (node *)malloc(sizeof(node));
    p->link->data = 2;
    p = p->link;
    p->link = (node *)malloc(sizeof(node));
    p->link->data = 3;
    p = p->link;
    int i = 0;
    while(i++ < 5){
        p->link = (node *)malloc(sizeof(node));
        p->link->data = 1;
        p = p->link;
    }
    p->link = (node *)malloc(sizeof(node));
    p->link->data = 4;
    p = p->link;
    p->link = (node *)malloc(sizeof(node));
    p->link->data = 10;
    p = p->link;
    p->link = NULL;

    deleteRepeatValue(head, N);

    p = head->link;
//    while(p != NULL){
    while(p){
        printf("The element is: %d\n ", p->data);

        p = p->link;
    }

    return 0;
}

void deleteRepeatValue(node *head, const int n){

    node *p = head;

    // 当传链表只有一个元素或无元素直接返回
//    if(p == NULL || p->link == NULL){
    if(!p || !p->link){
        return;
    }

    // 辅助数组
    int *auxArr = (int *)malloc(sizeof(int)*(n + 1));

    // 设置默认值 0
    int i = 0;
    while(i++ < n + 1){
        *(auxArr + i) = 0;
        // printf("The %d \n", *(auxArr + i));
    }

    // 删除重复元素
    i = 0;
    int temp = 0;
    node * del = NULL;
//    while(p->link != NULL){
    while(p->link){

        // 获取绝对值
        temp = p->link->data > 0 ? p->link->data : -p->link->data;

//        if( *(auxArr + temp) != 0){
        if( *(auxArr + temp)){
            // 记录需要删除的元素
            del = p->link;

            // 指针
            p->link = del->link;
        }else{
            // 记录元素
            (*(auxArr + temp))++;

            // 移动指针
            p = p->link;
        }

//        if(del != NULL){
        if(del){
            free(del);
        }
    }
    return ;
}



