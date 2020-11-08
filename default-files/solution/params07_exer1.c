//params07_exer1.c
//Passing C strings as parameter to functions
#include<stdio.h>

void input(char s[]) {
	printf("What is your name? ");
	scanf("%s", s);
	
}

void output(char s[]){
	printf("Your name is %s.\n",s);
}
	

int main(){
	char name[20]; //can store up to 19 input chars
	
	//#1 do this in the input function
	//printf("What is your name? ");
	//scanf("%s",name);
	
	input(name); 

	
	
	//#2 do this in the output function
	//printf("Your name is %s.\n",name);
	
	output(name);
	
}

