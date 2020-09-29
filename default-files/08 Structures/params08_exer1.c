//params08.c
//Passing C structure (or record) as parameter to functions
#include<stdio.h>

struct node_tag{
	char name[20];
	float grade;
};


void input(___){ //store values for r1

	printf("What is your name? ");
	scanf("%s",___);
	
	printf("What is your GWA? ");
	scanf("%f",___);
}

void output(___){ //display values of fields of r1
	printf("Name: %s\n",___);
	printf("GWA: %0.2f\n",___);
}


int main(){
	struct node_tag r1;
	
	//#1 do these lines in input function
	//printf("What is your name? ");
	//scanf("%s",r1.name);
	
	//printf("What is your GWA? ");
	//scanf("%f",&r1.grade);
	
	input(___);
	
	
	//#2 do this in output function
	//printf("Name: %s\n",r1.name);
	//printf("GWA: %0.2f\n",r1.grade);
	
	output(___);
	
}

