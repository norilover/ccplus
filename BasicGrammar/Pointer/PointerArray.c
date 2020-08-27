/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-27-21.39.23
* Description : 指针数组
*/
#include<stdio.h>

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
    i = 0;
    // extendArr(&tArr, LENGTH, LENGTH * 2);
    for( ; i <  LENGTH; ++i) {
        printf("tArr[%d] = %d\n", i, *(tArr + i));
    }


    return 0;
}

/***
 * 扩张数组[UN]
 **/
int extendArr(int **arr, int nowSize, int needSize) {
    int **tArr = NULL;
    *tArr = (int *)malloc(sizeof(int) * needSize);

    // 复制原来的元素
    int i = 0;
    for( ; i < nowSize; ++i) {
        *(*tArr + i) = *arr[i];
        printf("%d\n", *(*tArr + i));
    }

    free(arr);

    arr = tArr;

}
