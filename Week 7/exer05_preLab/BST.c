#include "BST.h"
#include <stdio.h>
#include <stdlib.h>
// include other headers u need

// a recursive subroutine to display the BST in tree mode
void showTreeHelper(BST_NODE* node, int tabs){
	if(node==NULL) return; // node is null, do nothing

	showTreeHelper(node->right, tabs + 1);
	for(int i=0; i<tabs; i++) 
		printf("\t");
	
	printf("%d(p%d)\n", node->key, node->parent==NULL?0:node->parent->key);
	//printf("%d\n", node->key); //use this instead to show nodes only
	
	showTreeHelper(node->left, tabs + 1);
}

void showTree(BST* B){
	printf("\n\nstart----------\n\n");
	showTreeHelper(B->root, 0);
	printf("\n------------end\n\n");
}

// insert your function definitions below
/*
** function: createBSTNode
** requirements:
    an integer indicating the key of the node
	L, R, or P are initialized as `NULL`
** results:
    creates a BST node with fields initialized
    returns a pointer of this instance
*/
BST_NODE* createBSTNode(int key){
	BST_NODE *new_node = (BST_NODE *)malloc(sizeof(BST_NODE));
	new_node->left=new_node->right=new_node->parent=NULL;
	new_node->key=key;
	return(new_node);
}


/*
** function: createBST
** requirements:
    NONE
** results:
    creates an empty BST with root field initialized to NULL
*/
BST* createBST(){
	BST *new_bst = (BST *)malloc(sizeof(BST));
	new_bst->root=NULL;
	return(new_bst);
}

/*
** function: isEmpty
** requirements:
    a non-null BST pointer
** results:
    returns 1 if BST is empty;
    otherwise, return 0
*/
int isEmpty(BST* B){
	return(B->root==NULL);
}

void insertR(BST_NODE **rootptr,BST_NODE *new){
  BST_NODE *temp=*rootptr; //temp=root in main

  if(*rootptr==NULL) 
	*rootptr=new;
  else{
	new->parent=*rootptr;
	if(new->key < (*rootptr)->key)
		insertR(&((*rootptr)->left),new);
	else insertR(&((*rootptr)->right),new);
  }
}

/*
** function: insert
** requirements:
    a non-null BST pointer
    a non-null BST_NODE pointer
** results:
    inserts the given `node` to the BST `B`
*/
void insert(BST* B, BST_NODE* node){
	insertR(&(B->root), node);
	//NOTE: this is just a place holder answer
	//      you have still have to implement 
	//      the non-recursive version of the insert function in Exer04
} 

/*
** function: search
** requirements:
    a non-null BST pointer
    a non-empty BST
    an integer `key`
** results:
    finds `key` from BST `B` and returns its node pointer if found, 
        otherwise, return `NULL`
*/
BST_NODE* search(BST* B, int key){
	BST_NODE *root=B->root;

	while(root!=NULL && root->key!=key){
		if(key < root->key) {
			root=root->left;
		}
		else{
			root=root->right;
		}
	}//while(1)
	return root;
}

/*
** function: clearNodeR
** requirements:
    a non-null BST pointer
** results:
    removes all the nodes of the BST.
*/
void clearNodeR(BST_NODE** node_ptr){
	BST_NODE *node=*node_ptr;
	if(node==NULL) return; // node is null, do nothing

	clearNodeR(&(node->left));
	clearNodeR(&(node->right));
	free(node);
	*node_ptr=NULL;
}

/*
** function: clear
** requirements:
    a non-null BST pointer
** results:
    removes all the nodes of the BST.
*/
void clear(BST* B){
	//recursively remove all the node
	clearNodeR(&(B->root)); 
	//NOTE: In the BST deletion exercise you have to 
	//      have to replace this with a reapeated 
	//      delete function call
	// while(!isEmpty(B)){ 
	// 	delete(B,B->root->key); 
	// 	showTree(B); 
	// }					
	
}

/*
** function: delete
** requirements:
    a non-null BST pointer
    a non-empty BST
    an integer `key`
** results:
    finds `key` and removes the key from BST `B`
*/


void delete(BST* B, int key){

	// basecase
	if(B->root == NULL) return;
	BST_NODE * root = B->root;
	deleteNode(root, key);
}

BST_NODE *  deleteNode(BST_NODE * node, int key){
	if(node == NULL) return node;
	BST_NODE * temp;
	if( key < node->key ){
		node->left = deleteNode(node->left, key);
	} else if( key > node->key ) {
		node->right = deleteNode(node->right, key);
	} else {
		// node with only one child or no child
		if( node->left == NULL ){
			temp = node->right;
			free(node);
			return temp;
		}else if ( node->right == NULL ){
			temp = node->left;
			free(node);
			return temp;
		} else {
			// node wit two children: get descendantSuccessor
			temp = minimum( node->right );
			// copy the key of successor to this node
			node->key = temp->key;
			// delete the successor
			node->right = deleteNode( node->right, temp->key);
		}
	}
	return node;


}


/*
** function: minimum
** requirements:
    a non-null BST pointer
    a non-empty BST
** results:
    finds the minimum `key` from BST `B` and returns its node pointer if found, 
        otherwise, return `NULL`
*/
BST_NODE* minimum(BST_NODE *node){
	if(node->left != NULL) minimum( node->left );
	else return node;
	//Pre-Lab Exercise: insert missing codes
    //it should return the minimum the right subtree
    //  rooted at the given node
	
	//called by descendantSuccessor
}


/*
** function: descendantSuccessor
** requirements:
    a non-null BST pointer
    a non-empty BST
	an integer `key`
	
** results:
    finds the descendant type of successor of the given `key` from BST `B` and returns its node pointer if found, otherwise, return `NULL`
*/
BST_NODE* descendantSuccessor(BST_NODE *node){

   //Pre-Lab Exercise: insert missing codes
   //it should return the minimum of the right subtree of the given node
   //you may call the minimum function
   BST_NODE * startNode = node->right;
   BST_NODE * successor = minimum(startNode);
   return(successor);
   
}