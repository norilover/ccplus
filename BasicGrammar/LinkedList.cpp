//**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-10-01-12.07.12
* Description : The initial LinkedList
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
#define ElemetType int
typedef struct LinkedList{
    ElemetType *data;
    int length;
    int maxSize;
}list, *LinkedList;

/***
 * The inital function
 * with the node of head
 **/
void initialList(list &head){
    head.data = (list *)malloc(sizeof(list) * SIZE);

    head.length = 1;
    head.maxSize = SIZE;

    assert(head.data != NULL);

    printf("The initialization is ok!");
}

/***
 * Exetend the length of data of LinkedList
 **/
void extendLinkedList(list &head, exLen){

    int i = 0;

    // the previous data of LinkedNode
    list *pre = head.data;

    // the new LisnkedList
    list *p = (list *)malloc(sizeof(list) * (list.maxSize + exLen));

    // receive the all element from the previous data of LinkedList
    for (; i < head.length; ++i){
        *(p + i) = *(pre + i);
    }

    // set the LinkedList
    head.data = p;

    head.maxSize = head.maxSize + exLen;
}


int main(){

    return 0;
}
