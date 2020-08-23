/**
* Copyright(c)
* All rights reserved.
* Author : nori
* Date : 2020-08-23-15.01.55
* Description : 结构体初始化总结
*/
#include<stdio.h>

/***
 * 结构体
 **/
typedef struct person {
    char *name;
    int age;
    const char sex;
}p;

/***
 * 输出结构体信息
 **/
void printPersonInfo(p *p1){
    printf("The character of person is: \n name: %s, \n age: %d, \n sex: %c \n", p1->name, p1->age, p1->sex);
}

int main(){

    // 法一
    p person1 = {"NORI", 23, 'M'};

    // 法二
    p person2 = {
        .name = "LILI",
        .age = 24,
        .sex = 'F'
    };


    // 法三
    p person3 = {
        name: "TOM",
        age: 25,
        sex: 'M'
    };

    printPersonInfo(&person1);
    printPersonInfo(&person2);
    printPersonInfo(&person3);

    // 结构体数组初始化
    p pArr[2] = {
        {
            name: "ADAM",
            age: 21,
            sex: 'M'
        },
        {
            name: "LISA",
            age: 22,
            sex: 'F'
        }
    };

    // 数组名默认为数组元素的首地址，即第一个元素的地址
//    printPersonInfo(pArr);
    printPersonInfo(&pArr[0]);

//    printPersonInfo(pArr + 1);
    printPersonInfo(&pArr[1]);

    return 0;
}
