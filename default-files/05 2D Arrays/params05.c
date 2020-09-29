//params05.c
//Passing a static 2D array as parameter to functions
#include<stdio.h>


//try these alternative formal parameters
//void input(int a[2][3], int n){	//valid, int a[2][3] decays to int a[][3]

void input(int a[][3], int m, int n){ 
	//"2D array a in main" has the address of 
	//"a[0][0] in main"
	int i,j;
	
	for(i=0;i<m;i++) {
		printf("\nEnter %i integers for row %i\n", n,i+1);
		for(j=0;j<n;j++) {
			printf("Enter an integer: ");
			scanf("%i",&a[i][j]);
		}		
	}
}

void output(int a[][3], int m, int n){ //see comments in input
	int i,j;
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++) {
			printf("%3i ",a[i][j]);
		}		
		printf("\n");
	}
}


int main(){
	int m=2, n=3;
	int a[m][n];
		
	input(a, m, n); // pass a 2D array variable a as parameter into input function
	output(a, m, n);// pass a 2D array variable a as parameter into output function
}
					