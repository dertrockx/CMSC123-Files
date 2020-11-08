//params03_exer1.c
//Exercise: Passing an array as parameter to functions
#include<stdio.h>

void input(int a[], int n){ //should get user inputs for n integers
						// and store it in "array a in main"
	int inp, i;
	for( i = 0; i < n; i++){
		printf("Enter an integer: ");
		scanf("%i",&a[i]);
	}
}

void output(int a[], int n){ //should print n integers from "array a in main"
	int i;
	for(i=0;i<n;i++) {
		printf("a[%i]==%i\n",i,a[i]);
	}	
}


int main(){
	int i, n=5;
	int a[n];
	
	//#1 do this in the input function
	//get user inputs for n integers and store it into array a
	//for(i=0;i<n;i++) {
	//	printf("Enter an integer: ");
	//	scanf("%i",&a[i]);
	//}
	
	input(a, n); // pass array variable a as parameter into input function
					
	
	
	//#2 do this in the output function
	//display the contents of array a
	//for(i=0;i<n;i++) {
	//	printf("a[%i]==%i\n",i,a[i]);
	//}	
	
	output(a, n);// pass array variable a as parameter into output function
}
					