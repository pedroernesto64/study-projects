#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void CurrentStack (int *stack, int top) { //Prints all elements from the stack
	int i;
	printf ("Current stack: ");
	for (i=1; i<=top; i++) {
		printf ("%d ", stack[i]);
	}
	printf ("\n");
}

int IsEmpty (int top) { //Verifies if the stack is empty
	if (top==0) {
		printf ("The stack is empty\n");
		return 1;
	}
	else {
		return 0;
	}
}

int IsFull (int max, int top) { //Verifies if the stack is full
	if (top==max) { 
		printf ("The stack is full\n");
		return 1;
	}
	else {
		return 0;
	}
}

void Push (int *stack, int insert, int top) { //Inserts an element, and later prints the stack
	stack[top+1]=insert;
	CurrentStack(stack, top+1);
}

//---------------------------------

int main () {
	int *stack;
	int n, option, insert, top=0;
	
	printf ("Type the size of the stack: ");
	scanf ("%d", &n);
	printf ("\n");
	stack=(int *) malloc (n * sizeof(int)); //Starts the stack with the desired size
	while (option!=4) {
		printf ("Select an operation (1-push / 2-pop / 3-top / 4-end): ");
		scanf ("%d", &option);
		switch (option) {
			case 1: //Case "Push" (inserts an item)
				if (IsFull(n, top)==0) { //Verifies if an element can be added
					printf ("Type the number you want to add: ");
					scanf ("%d", &insert);
					printf ("\n");
					Push(stack, insert, top);
					top++;
				}
				break;
			case 2: //Case "Pop" (removes the latest item)
				if (IsEmpty(top)==0) { //Verifies if an element can be removed
					top--; //Decreases the top index, ignoring the next value
					CurrentStack(stack, top);
				}
				break;
			case 3: //Case "Top" (prints the value of the last item)
				if (IsEmpty(top)==0) {
					printf ("Stack top: %d\n", stack[top]);
				}
				break;
		}
	}
	
	return 0;
}
