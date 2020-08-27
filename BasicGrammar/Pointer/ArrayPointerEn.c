#include<stdio.h>
/***
 * 数组指针进阶
 */

/***
 * 数组大小
 */
#define SIZE_ARRAY 10

int main(char args, char **argv) {
	int *arr[10] ;

	arr[0] = (int *)malloc(sizeof(int) * SIZE_ARRAY);
	
	int i = 0;
	for( ; i < SIZE_ARRAY; i++) {
		*(arr[0] + i) = 1 << i;

		printf("The element is: %d\n", *(arr[0] + i));
	}

	return 0;

}
