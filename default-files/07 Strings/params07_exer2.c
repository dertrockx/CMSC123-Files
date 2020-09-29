//params07_exer1.c
//Exercise on Passing C strings as parameter to functions
#include<stdio.h>
#include<string.h>	
#include<ctype.h>	//character manipulation functions

void input(char *s) { 
	printf("What is your name? ");
	scanf("%s",s);
	
}

//fill the missing formal parameter and use the toupper function 
// in ctype.h to convert string parameter upper case
void toupperStr(____){ 
	//fill the missing codes
	//mind the termnating character of the string
	//when calling toupper function inside the loop
}

void output(char *s){
	printf("Your name is %s.\n",s);
}
	

int main(){
	char name[20]; 
	
	input(name); 
	output(name);
	
	toupperStr(___); //use toupper function in ctype.h to 
					  // convert name to upper case
	
	output(name);
	
}

