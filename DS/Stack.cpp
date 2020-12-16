#include<iostream>
#include<stdio.h>

using namespace std;

class Stack{
	private:
			static const int max = 100;
			int arr[max];
			int top;

	public :
			Stack(){
					top = -1;
			}
			bool isEmpty();
			bool isFull();
			int top();
			void push(int x);
				
};


bool Stack::isEmpty(){
	if(top == -1){
		return true;
	}

	return false;
}

bool Stack::isFull(){
	if(top == max - 1){
		return true;	
	}

	return false;
}

bool Stack::pop(){
	if(isEmpty()){
		cout << "Stack is full");
		abort();
	}

	int x = arr[top];
	top--;
	return x;
}

void Stack::push(int x){
	if(isFull()){
		cout << "Stack is full");
		abort();
	}

	top++;
	arr[top] = x;
}

// Inherite the stack
class SpecialStack : public Stack{
	
}



