/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-27-21.39.23
* Description : 指针数组
*/
#include<stdio.h>
#include<stdlib.h>

// 指针数组长度
#define LENGTH 10

/***
 * 扩张数组
 **/
int extendArr(int **arr, int nowSize, int needSize);

int main(){
    int *arr[LENGTH];

    int i = 0;
    for( ; i < LENGTH; ++i) {
        arr[i] = (int *)malloc(sizeof(int) * LENGTH);
        int j = 0;
        for( ; j < LENGTH; ++j) {
            arr[i][j] = 1 << j;
            // 等价形式
            // *(arr[i] + j) = 1 << j;
            // (*(arr + i))[j] = 1 << j;
            //  *(*(arr + i) + j) = 1 << j;

            printf("The value of element is: %d\n", arr[i][j]);
        }
    }

    int *tArr = arr[0];
    
    // 扩展空间
    extendArr(&tArr, LENGTH, LENGTH << 1);

    // 遍历新的数组地址元素值
    i = 0;
    for( ; i <  LENGTH << 1; ++i) {
        printf("tArr[%d] = %d\n", i, *(tArr + i));
    }

    return 0;
}

/***
 * 扩张数组[UN]
 **/
int extendArr(int **arr, int nowSize, int needSize) {
    int **tArr = NULL;

    // 创建新数组空间
    tArr = (int *)malloc(sizeof(int) * needSize);
    if(tArr == NULL){
        return -1;
    }

    // 复制原来的元素
    int i = 0;
    for( ; i < nowSize; ++i) {
        *(*tArr + i) = *(*arr + i);
	// 等价形式
	// *(tArr[i]) = *(arr[i]);

        printf("%d\n", *(*tArr + i));
    }

    // 赋值剩余元素
    while(i < needSize) {
        *(*tArr + i) = -1; 
    }

    // 释放原来的空间
    free(arr);

    // 将原来的数组的指针的指针指向新的地址
    arr = tArr;

}
