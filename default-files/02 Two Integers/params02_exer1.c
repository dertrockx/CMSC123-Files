//params02_exer1.c Passing two integers as parameters
//Exercise: fill in the blanks to make this work like params02.c

#include<stdio.h>

void input(___ , ___){ 
	
	printf("Enter two integers (e.g. 21 123): ");
	scanf("%i %i",___,___);
}


void output(___, ___){	
	printf("a==%i b==%i\n",___,___); 
}

int main(){
	int a=21, b=123;
	
	//#1 do this in the input function
	//printf("Enter an two integers: ");
	//scanf("%i %i",&a, &b); //pass-by-reference
	
	input(___,___); //should ask for user input for a and b, respectively
	
	
	//#2 do this in the output function
	//printf("a==%i a==%i\n",a,b); 	// pass-by-value
	
	output(___,___); //should print the values of a and b, respectively

}
					