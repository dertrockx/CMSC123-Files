//params10_exer1.c
//Exercise: Parameter passing for linked list in C

#include<stdio.h>
#include<malloc.h>

typedef struct node_tag{
	int x;
	struct node_tag *next;
}node; 


void output(___){ //should display all the contents of the list
	
}

void deallocate(___){ //should deallocate all the nodes of the list	
					  
	
}

int main(){
	node *h, *temp;

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
	
	//#1 do this loop in the output function
	//display the contents of the linked list
	//temp=h;
	//while(temp!=NULL){
	//	printf("%3i ",temp->x);
	//	temp=temp->next;
	//}
	//printf("\n");
	
	output(___);
	
	//#2 do this loop in the deallocate function
	//dynamic de-allocation
	//while(h!=NULL){
	//	temp=h;
	//	h=h->next;
	//	free(temp);
	//}
	
	deallocate(___);
}
