#include<iostream>
#include<cstack>
/***
 * POST TRAVERSE
 */

#define SIZE 10;

typedef struct TreeNode {
	int val;
	struct TreeNode leftNode;
	struct TreeNode rightNode;
}tn;

int post_traverse(tn *root){
	tn *p = root;
	tn *pre = NULL;
	
	// use to repository the left node
	Satck<tn *> s;

	while(!s.empty() || p){
		if(p){
			// record the all left node
			s.push(p);
			p = p->leftNode;
		}else{
			p = stack.getTop();

			// Go to the right node until the right node is null
			if(p != pre && p->rightNode){
				p = p->rightNode;
				s.push(p);

				// Go on the left node
				p = p->leftNode;
			}else{
				// Visiting the p of node				
				visit(p);

				// remove and record the visited node
				pre = s.pop();

				// Settin NULL of p's value
				p = NULL;
			}
		}
	}
	return 1;
}

int main(int argc, char **args){
	tn *root = (tn *)malloc(sizeof(tn) * SIZE);
	post_traverse(root);

	return 0;
}

