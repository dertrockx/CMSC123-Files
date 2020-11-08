#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int postfix(char *postfixString){
	STACK *S = createStack(); //uncomment to create stack
	int i,n=strlen(postfixString);
	int ch;

    //uncomment this block comment to check some useful loops
	// printf("check characters from the postfixString\n");
	// for(i=0;i<n;i++){
	// 	ch=postfixString[i];
	// 	printf("char code:%i character:\'%c\'  int value:%i\n", ch, ch, ch-'0');
	// }

	// printf("\ncheck digits from the postfixString\n");
	// for(i=0;i<n;i++){
	// 	ch=postfixString[i];
	// 	if(isdigit(ch)){ //check if c is a digit (from ctype.h)
	// 		printf("char code:%i character:\'%c\'  int value:%i\n", ch, ch, ch-'0');
	// 	}
	// }

	for (i = 0; i < n; i++){
		ch = postfixString[i];
		if ( isdigit (ch) ){
			push(S, createNode(ch-'0'));
		} else {
			int a = pop(S);
			int b = pop(S);
			int c = 0;
			switch(ch){
				case '+':
					c = b + a;
					// printf("%i + %i\n", b, a);
					break;
				case '-':
					c = b - a;
					// printf("%i - %i\n", b, a);
					break;
				case '*':
					c = b * a;
					// printf("%i * %i\n", b, a);
					break;
				case '/':
					c = b / a;
					// printf("%i / %i\n", b, a);
					break;
			}
			// printf("c = %i\n", c);
			push(S, createNode(c));
		}
	}
	// show(S);
	//In-Lab Exercise: Fill the missing codes
	return pop(S);
    // return -1; //stub value, don't forge to replace it with the right value
}

int main(){

	//char postfixString[100];
	char *postfixString="62/12+*";
	// postfixString = "72*3+5-";
	// postfixString = "3564-+*";
	// postfixString = "02/";
	postfixString = "9";
	int i;



	//printf("Enter Postfix expr: ");
	//scanf("%s",postfixString);

	printf("the postfix value of %s = %i\n\n",postfixString, postfix(postfixString));

}
