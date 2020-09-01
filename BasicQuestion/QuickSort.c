#include<stdio.h>
#include<stdlib.h>

/***
 * print array
 */
void print(int *a, int len){
	int i = 0;
	while(i < len){
		printf("The element is: %d\n ", *(a + i));
		i++;
	}
	return ;
}
/***
 * Quick Sort
 */
int quickSort(int *arr, int le, int ri){
	if(le > ri)
		return 0;
	
	int pivot = partition(arr, le, ri);

	quickSort(arr, le, pivot - 1);	
	quickSort(arr, pivot + 1, ri);

	return 0;
}
/***
 * Find the Pivot
 */
int partition(int *arr, int le, int ri){
	int pivot =  *(arr + le);

	while(le < ri){
		while(le < ri && *(arr + ri) >= pivot){
			ri--;
		}
		*(arr + le) = *(arr + ri); 

		while(le < ri && *(arr + le) < pivot){
			le++;
		}
		*(arr + ri) = *(arr + le);
	}
	// Put the element on final position
	*(arr + ri) = pivot;

	return le;
}

int main(char args, int argv){
	int arr[] = {4,1,2,4,5};

	printf("The previous sequence of array\n");
	print(arr, sizeof(arr)/sizeof(int));

	// Sort Array
	quickSort(arr, 0, sizeof(arr)/ sizeof(int) - 1);

	printf("The final sequence of array\n");
	print(arr, sizeof(arr)/sizeof(int));
	return ;
}
