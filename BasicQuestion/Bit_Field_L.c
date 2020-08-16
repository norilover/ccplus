/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-12-21.38.03
* Description : 位字段
*/
#include<stdio.h>
struct {
    // 只使用2位, 追多表示十进制3
    unsigned int red : 2;
    unsigned int yellow : 2;
    unsigned int blue : 2;
    unsigned int green : 2;
}my_color;
typedef struct color{
    // 只使用2位, 追多表示十进制3
    unsigned int red : 2;
    unsigned int yellow : 2;
    unsigned int blue : 2;
    unsigned int green : 2;
}my_color1;
int main(){

    // 声明一个指针指向 struct color 内存区域
    // my_color1 *color1 = (my_color1 *)malloc(sizeof(my_color1));

    // 直接使用struct my_color操作
    // 00
    my_color.red = 0;
    // 01
    my_color.yellow = 1;
    // 10
    my_color.blue = 2;
    // 11
    my_color.green = 3;
    printf("%d, %d, %d, %d\n", my_color.red, my_color.yellow, my_color.blue, my_color.green);

    // 11
    my_color.red = 3;
    // 00
    my_color.yellow = 4;
    // 01
    my_color.blue = 5;
    // 10
    my_color.green = 6;
    printf("%d, %d, %d, %d\n", my_color.red, my_color.yellow, my_color.blue, my_color.green);

    return 0;
}
