//Binary tree Breadth First Search

#include <stdio.h>
#include <stdlib.h>

//actual binary tree node
typedef struct bnode{
	int value;
	struct bnode *left;
	struct bnode *right;
} bnode;

//globals
bnode *root = NULL;
int val;
int front = 0;
int rear = -1;
int i;
int queue[20]; //was for bfs


//function declarations
//now don't have to put these functions before main
void insert(bnode *, bnode *);



//inserts a new  bnode one into the tree recursively
// bnode one: node to be inserted
// bnode root: root of the tree
void insert(bnode * one , bnode *root){

	if(one->value > root->value){
		//if theres nothing to the right
		//since the one node is larger
		//insert it to the right of root
		if (root->right == NULL) {
            root->right = one; 
		}

		//pretend there is a new tree where
		//the root is one level deeper to the right
        else {
            insert (one, root->right); 
        }
	}

	if (one->value < root->value){
		if (root->left  ==  NULL) {
            root->left = one; 
		}
        else {
            insert (one, root->left); 
        }
	}

}



//Enter the elements, which are inserted into BT
//Then traverse the elements, stored in a queue which
//is then displayed.
//Taken from the interwebs
int main(int argc, char *argv[]){
	bnode *one = NULL;
	int num = 1;

	printf("Enter the elements of the tree(Enter 0 to exit)");
	while(1){
		scanf("%d", &num);
		if (num  ==  0) 
            break;

        //keep inserting numbers as long as you enter numbers

        one = malloc(sizeof(bnode)); 
        one->left = NULL;
        one->right = NULL; 
        one->value = num; 

        if (root == NULL) 
            root = one; 
        else 
        { 
        	//actually put it in the tree
            insert(one, root); 
        } 
	}

	//to verify that the tree is being made right
    printf("Printing root, left, and right\n");
    printf("%d\n", root->value);
    printf("%d\n", root->left->value);
    printf("%d\n", root->right->value);


}
