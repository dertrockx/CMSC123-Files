/*
    @author
    Ian Salazar
    2019-04060
    CMSC 123 U2
*/

#include "stack.h"


/*
** function: createStack
** requirements:
    none
** results:
    creates an empty stack with specified max length

*/

STACK * createStack(){
    /*
        Since `STACK` is the same as a list,
        we can use the methods of list
        i.e. to create a list, use createList()

        returns an empty list
    */
    return( createList() );
}

/*
** function: push
** requirements:
	stack must not be full.

** results: inserts `node` at the head of the list.

** sample: L = [12, 6, 4, 10]
** push(L, createNode(55)) -> L = [12, 6, 4, 10, 55]
** push(L, createNode(44)) -> L = [12, 6, 4, 10, 55, 44]
** push(L, createNode(66)) -> L = [12, 6, 4, 10, 55, 44, 66]
*/
void push(STACK * S, NODE * node){
    insertHead(S, node);
}

/*
** function: pop
** requirements:
	stack must not be empty
** results:
	deletes node at position head of the list
	returns the value of the deleted node.
** sample: L = [44, 12, 6, 55, 4, 10, 66]
** pop(L) -> L = [12, 6, 55, 4, 10, 66]; returns 44
** pop(L) -> L = [6, 55, 4, 10, 66]; return 12
** pop(L) -> L = [55, 4, 10, 66]; returns 6
*/
int pop( STACK * S){
    return deleteHead(S);
}

