//params07_exer1.c
//Passing C strings as parameter to functions
#include<stdio.h>

void input(___) {
	printf("What is your name? ");
	scanf("%s",____);
	
}

void output(___){
	printf("Your name is %s.\n",___);
}
	

int main(){
	char name[20]; //can store up to 19 input chars
	
	//#1 do this in the input function
	//printf("What is your name? ");
	//scanf("%s",name);
	
	input(___); 

	
	
	//#2 do this in the output function
	//printf("Your name is %s.\n",name);
	
	output(___);
	
}

