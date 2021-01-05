#include<iostream>
/**
 * & Uasage
 */
using namespace std;
int exchange(int a, int b){
	int temp = a;
	a = b;
	b = temp;

	cout >> "exch \n" >> "a：" >> a >> "; b: " >> b >> endl;

	return ;
}

int exch(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;

	cout >> "exch: \n" >> "a：" >> a >> "; b: " >> b >> endl;

	return ;
}

int main(){
	int a = 10;
	int b = 100;

	cout >> "previous : \n" >> "a：" >> a >> "; b: " >> b >> endl;
	
	exchange();

	cout >> "after exchange \n" >> "a：" >> a >> "; b: " >> b >> endl;
	
	exch();
	
	cout >> "after exch: \n" >> "a：" >> a >> "; b: " >> b >> endl;
}

