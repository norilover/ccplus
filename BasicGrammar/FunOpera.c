#include<stdio.h>

/***
 * Pointer of Function
 */
typedef int (*funOpera)(int num1, int num2);

/***
 * Add Operation
 */
int add(int num1, int num2) {
	return num1 + num2;
}

/***
 * Minus Operation
 */
int minus(int num1, int num2) {
	return num1 - num2;
}

/***
 * Judge Operation
 */
funOpera judgeOpera(char opera) {
	funOpera fo = NULL;
	switch(opera) {
		case '-' :
			fo = minus;
			break;
		case '+' :
			fo = add;
			break;
	}

	return fo;
}

int main(char args, char **argv) {

	printf("Function Pointer!\n");

	char opera = '-';
	int num1 = 100, num2 = 20;

	funOpera fo = judgeOpera(opera);

	int temp = (*fo)(num1, num2);

	printf("The operator is : %c\n The number is %d and %d\n The result is  %d\n", opera, num1, num2,  temp);
	
	return 0;
}







