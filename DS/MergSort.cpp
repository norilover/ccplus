#include<iostream>

using namespace std;











void Merge(int[] arr, int left, int middle, int right){
	int n1 = middle - left + 1;
	int n2 = right = middle + 1;

	int [n1]arr1, [n2]arr2;

	// 1.
	for(int i = 0; i < n1; i++){
		n1[i] = arr[i];	
	}

	for(int i = 0; j < n2; j++){
		n2[i] = arr[i + middle];
	}

	// 2.1Get one array from the n1 and n2
	int k = left;
	int i = 0, j = 0;
	for(; i < n1 && j < n2;){
		if(arr1[i] < arr2[j]){
			arr[k++] = arr1[i++];
		}else{
			arr[k++] = arr2[j++];
		}
	}

	// 2.2 Get 
	while(i < n1){
		arr[k++] = arr1[i++];
	}
	while(j < n2){
		arr[k++] = arr2[j++];
	}

	return ;



        	
}



void MergeSort(int[] arr, int left, int right){
	if(left >= right){
		return ;
	}

	int middle = (right + left) / 2;

	MergeSort(arr, left, middle);
        MergeSort(arr, middle + 1, right);	
	
	Merge(arr, left, middle, right);

}


int main(){
	int[] arr = {4,2,1,2,4,5};
	int length = sizeof(arr);
	MergeSort(arr, length);
	

	for(int i = 0; i < length; i++){
		cout << arr[i] << "\n" << endl;
	}
}
 



 


