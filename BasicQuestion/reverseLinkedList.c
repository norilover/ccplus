#include<stdio.h>
#include<stdlib.h>
/***
 * reverse the LinkedList
 */

typedef int ElemType;

/***
 * Definition of Node
 */
typedef struct Node {
	ElemType val;
	struct Node *next;	
}n;

/***
 * Definition of LinkedList
 */
typedef struct LinkedList {
	n *head;	
	int size;
}LL;

/***
 * print the info of LinkedList
 */
int printList(n *head) {
	n *p = head;
	while(p != NULL){
		printf("The value of node is : %d\n", p->val);
			
		// move pointer to next;
		p = p->next;
	}

	return 0;
}

/***
 * reverse the LinkedList
 */
int reverseList(LL *llist){
	// return -1 if the LinkedList is empty;
	if(llist->head == NULL){
		return -1;
	}

	LL *list = llist;
	n *p = list->head;

	// Jump the node of head
	p = p->next;
	n *q = p->next , *temp = NULL;
	p->next = NULL;

	while(q != NULL){
		temp = q->next;
	     	
		// Way of classic reversion
		q->next = p;
		p = q;

		q = temp;
	}	
	
	// change the head->next of  LinkedList 
	list->head->next = p;

	return 0;
}

int main(char args, char *argv) {
	// Create the data
	// Node of head
	n *p = (n *)malloc(sizeof(n));

	LL *llist = (LL *)malloc(sizeof(LL));
	llist->head = p;
	p->val = -1;

	// Give the value of node
	int num = 10;
	while(num-- > 0){
		p->next = (n *)malloc(sizeof(n));
		p = p->next;	

		p->val = 1 << num;
	}
	// The node of tail is NULL
	p->next = NULL;

    // print
    printf("The previous sequence of LinkedList: \n");
	printList(llist->head);

	reverseList(llist);	

    printf("The reversed sequence of LinkedList: \n");
	printList(llist->head);

	return 0;
}

