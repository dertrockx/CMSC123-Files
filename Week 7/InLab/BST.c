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
	
	// clearNodeR(&(B->root)); //you may still use this while
	                        //you are not yet done implementing the delete function
	
	//In-Lab Exercise:  when you are done with your delete function,
	//                  comment out clearNodeR(&(B->root));
	//                  uncomment the next line to test your delete function
	while(!isEmpty(B)){ 
		delete(B,B->root->key); 
		showTree(B); 
	}					
	
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
	B->root = deleteNode(B->root , key);
}

BST_NODE *  deleteNode(BST_NODE * root, int key){
	// / base case 
    
    if (root == NULL) return root; 
    // printf("a\n");
    
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
    {
        root->left = deleteNode(root->left, key); 
        // printf("b\n");
    }
        
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) {
        root->right = deleteNode(root->right, key); 
        // printf("c\n");
    }
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // printf("d\n");
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            // printf("e\n");
            BST_NODE * temp = root->right; 
            // printf("e1\n");
            free(root); 
            // printf("e2\n");
            return temp; 
            
            
        } 
        else if (root->right == NULL) 
        { 
            // printf("f\n");
            BST_NODE * temp = root->left; 
            // printf("f1\n");
            free(root); 
            // printf("f2\n");
            
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        // printf("g\n");
        BST_NODE * temp = minimum(root->right); 
        // printf("h\n");
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
        // printf("i\n");
        // Delete the inorder successor 
        // printf("j\n");
        if( root->right != NULL )
            root->right = deleteNode(root->right, temp->key); 
        else 
            root->left = deleteNode(root->left, temp->key);
    } 
    return root; 


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

void inorderWalk(BST * B){
	printInOrder(B->root);
}

void preorderWalk(BST * B){
	printPreOrder(B->root);
}

void postorderWalk(BST * B){
	printPostOrder(B->root);
}

void printInOrder(BST_NODE* node) {
	if( node->left != NULL ){
		printInOrder( node->left );
	}
	printf("%d ", node->key);
	if( node->right != NULL){
		printInOrder( node->right );
	}
}

void printPreOrder(BST_NODE * node){
	printf("%d ", node->key);
	if( node->left != NULL ){
		printPreOrder( node->left );
	}
	if( node->right != NULL){
		printPreOrder( node->right );
	}
}

void printPostOrder(BST_NODE * node){
	if( node->left != NULL ){
		printPostOrder( node->left );
	}
	if( node->right != NULL){
		printPostOrder( node->right );
	}
	printf("%d ",node->key);
}