/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-23-08.46.26
* Description : 使用指针实现数组（在C中数组传递只是数组的首地址，所以只传递数组，无法判断数组的结束位置， 但对于char类型的数组可以通过'\0'来判断）
*/
#include<stdio.h>

#define EleSize 10

/***
 * 遍历数组，常规法
 **/
void traverseArrayCommon(int args, int argv[]);
// int traverseArrayCommon(int args, int *argv);

/***
 * 遍历数组，指针法
 **/
void traverseArrayPointer(int args, int *argv, int *argv1);

int main(){

    int array[EleSize];
    int i = 0;
    while (i < EleSize) {
        array[i++] = i * 10;
    }

    // 常规法遍历数组
    traverseArray(EleSize, array);


    int array1[EleSize];
    i = 0;
    while (i < EleSize) {
        array1[i++] = 1 << i;
    }

    // 指针法遍历数组
    traverseArrayPointer(EleSize, array, array1);

    return 0;
}

/***
 * 遍历数组，常规法
 **/
void traverseArray(int args, int argv[]) {
    printf("The common way traverse array: \n");

    int i = 0;
    for( ; i < args; i++){
        int temp = argv[i];
        // int temp = *(argv + i);

        printf("The No. %d is: %d\n", i, temp);
    }

    return ;
}

/***
 * 遍历数组，指针法
 **/
void traverseArrayPointer(int args, int *argv, int *argv1){
    // 双重指针
    // *douPoin 指向数组 argv的起始地址
    int **douPoin = NULL;

    // 遍历 argv
    douPoin = &argv;
    int i = 0;
    printf("The pointer way traverse array: \n");
    while(i < args) {
        int temp = *(*douPoin + i);
        printf("The No. %d is: %d\n", i, temp);
        i++;
    }

    // 遍历 argv1
    douPoin = &argv1;
    i = 0;
    printf("The pointer way traverse array1: \n");
    while(i < args) {
        int temp = *(*douPoin + i);
        printf("The No. %d is: %d\n", i, temp);
        i++;
    }

    return ;
}


