//params10_exer2.c
//Parameter passing for linked list in C

//Exercise: implement the append function

#include<stdio.h>
#include<malloc.h>

typedef struct node_tag{
	int x;
	struct node_tag *next;
}node; 


void output(node *h){ //display all the contents of the list
	node *temp;				  
	
	temp=h;
	while(temp!=NULL){
		printf("%3i ",temp->x);
		temp=temp->next;
	}
	printf("\n");
}

void deallocate(node **hptr){ //deallocates all the nodes of the list	
	node *temp;				  
	
	while((*hptr)!=NULL){
		temp=(*hptr);
		(*hptr)=(*hptr)->next;
		free(temp);
	}
}

void append(___, int x){ //should append a new node at the end of the list
	//Hint: make sure that you have done pen-and-paper 
	//      exercise for linked list before you attempt to do this
}

int main(){
	node *h=NULL, *temp;

	//Final Exercise: do these in an append function
	
	/*
	//first node
	h=(node *)malloc(sizeof(node));
	h->x=1;
	h->next=NULL;
	
	//second node
	h->next=(node *)malloc(sizeof(node));
	h->next->x=2;
	h->next->next=NULL;
	
	//third node
	h->next->next=(node *)malloc(sizeof(node));
	h->next->next->x=3;
	h->next->next->next=NULL;
	*/
	
	append(___,1); //appends the first node
	append(___,2); //appends the second node
	append(___,3); //appends the third node
	append(___,4); //we can even append a fourth node
	
	
	//display the contents of the linked list
	output(h);
	
	//dynamic de-allocation
	deallocate(&h);
}
