/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-09-19.53.15
* Description : #define & typedef 的使用
*/
#include<stdio.h>
// 定义宏；
#define MY_PI 3.14;
#define _ 1000;
// 定义宏函数；
#define SUM(x, y) ((x < 0 ? 0 : x) + (y < 0 ? 0 : y));

// 定义类型；
typedef char CHAR;
// 类似#define的用法；

int exchange(int *a, int *b);
int main(){
    CHAR c = 'c';
    printf("%c\n", c);

    float f = MY_PI;
    printf("%f\n", f);

    int i = _;
    printf("%d\n", i);

    int sum = SUM(10, -1);
    printf("%d\n", sum);
    sum = SUM(10, 10);
    printf("%d\n", sum);

    return 0;


}

int sum(int a, int b){
    return a + b;
}
