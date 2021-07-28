# include "Sorting.h"

int test_arraySort(){

	Stack* S = newStack(5);
	push(S, 2);
	push(S, 5);
	push(S, 3);
	push(S, 8);
	push(S, 14);
	show(S, 1);
	
	// Sort the underlying memory
	arraySort(S);
	show(S, 1);
	
	return 0;

}

