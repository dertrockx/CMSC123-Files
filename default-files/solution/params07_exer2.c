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
void toupperStr( char * s){ 
	//fill the missing codes
	//mind the termnating character of the string
	//when calling toupper function inside the loop
	int n = strlen(s);
	for( int i = 0; i < n; i++){
		s[i] = toupper(s[i]);
	}
}

void output(char *s){
	printf("Your name is %s.\n",s);
}
	

int main(){
	char name[20]; 
	
	input(name); 
	output(name);
	
	toupperStr(name); //use toupper function in ctype.h to 
					  // convert name to upper case
	
	output(name);
	
}

