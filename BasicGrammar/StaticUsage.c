/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-22-16.51.45
* Description : Static的各种用法
*/
#include<stdio.h>

/***
 * static 声明类似全局变量的特性
 **/
void staticUsage1();

int main(){

    int i = 0;
    for (; i < 10; i++){
        // 打印 1 ... 9
        staticUsage1();
    }
    // 报错不可直接调用staticUsage1()中的ind
    // printf("The final ind is: %d\n", ind);


    return 0;
}

/***
 * static 声明类似全局变量的特性
 **/
void staticUsage1(){
    // 存储于全局变量区域
    static int ind = 0;

    // 连续累加ind
    ind++;
    printf("The ind is: %d\n", ind);
}
