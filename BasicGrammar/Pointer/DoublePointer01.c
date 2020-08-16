/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-16-09.13.21
* Description : 双重指针使用
*/
#include<stdio.h>

int main(){
    // 书名数组指针
    char *titles[] = {"Game of Throne",
                     "The Thorn Birds",
                     "Aesop's Fables",
                     "The Three Musketeers",
                     "Mysterious Island",
                     "Encircle A City"};


    // 指向指针的指针
    char **best_books[3];
    char **popular_books[3];

    best_books[0] = &titles[1];
    best_books[1] = &titles[5];
    best_books[2] = &titles[2];

    popular_books[0] = &titles[0];
    popular_books[1] = &titles[2];
    popular_books[2] = &titles[5];

    // 指针的地址
    printf("The name of book is: %p\n", &titles[5]);
    printf("The name of book is: %p\n", popular_books[2]);

    // 指针所指向元素的地址
    printf("The name of book is: %p\n", titles[5]);
    printf("The name of book is: %p\n", *popular_books[2]);

    // 元素地址所存储在值
    printf("The name of book is: %c\n", **popular_books[2]);


    // 遍历 titles[5] 中元素
//    char * t = titles[5];
    char * t = *best_books[1];
//    char * t = *popular_books[2];

    printf("The name of book is: ");

    // 字符串以 '\0' 结尾
    while(*t != '\0'){
        printf("%c", *t);
        t++;
    }

    printf("\n");


    return 0;
}
