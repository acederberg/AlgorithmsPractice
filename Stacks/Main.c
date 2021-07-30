# include "Stack.h"

void StackDemo(){

	Stack* S = newStack(16);
	show(S, 1);

	printf("\nPushing some integers onto the stack...\n");
	push(S, 7);
	push(S, 8);
	push(S, 15);
	show(S, 1);

	printf("\nRemoving some integers from the stack...\n");
	pop(S);
	pop(S);

	printf("\nFilling the remaining stack with an array...\n");
	show(S, 1);

	int values[] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987} ;
	int *temp = values;
	while ( push(S, *temp) ){ temp++; }

	show(S, 0);

	printf("\nRemoving the stack contents...\n");
	while ( pop(S) ){ show(S, 1); }
	printf("HERE\n");
	show(S, 1);

}

void SuperDemo(){

	Stack* S = newStack(8);
	show(S, 1);

	printf("\nFilling a stack with Lucas numbers...\n");
	int values[] = {2,1,3,4,7,11,18,29,47,86};
	push(S, values, 10);
	show(S, 1);

	for (int k = 0; k < 2; k++){

		printf("\nCounting the number of values equal to 1 in stack... ");
		printf("count = %i\n", count(S, 1));

		if ( k == 1 ){	continue;	}
		printf("\nInserting a few more numbers to test `count`.\n");
		int more_values[] = {1,2,3,4,5,1,3,4,8,3,1,4,62,3,4,1};
		push(S, more_values, sizeof(more_values) / sizeof(int));
		show(S, 1);

 	}

 	int mins[] = {0, 10, 100};
 	int maxs[] = {10, 100, 1000};

 	for (int k = 0; k < 3; k++){
 		printf("\nNow counting the number of entries between %i  and %i... count = %i\n", mins[k], maxs[k], count(S, mins[k], maxs[k]) );
 		show(S, 1);
 	}

}

// void SuperDemo0(){
//
// 	Stack* S = newStack(8);
// 	int values[] = {1,2,3,4,5};
// 	push(S, values, 5);
// 	show(S, 1);
//
// 	printf("\nInserting a value in position 2.\n");
// 	insert(S, 2, 444);
// 	show(S, 1);
//
// 	// printf("\nRemove that value.\n");
// 	// remove(S, 2);
// 	show(S, 1);
//
// 	printf("\nRemoved 3 values.\n");
// 	pop(S, 3);
// 	show(S, 1);
// }

int main(){

	SuperDemo();
	return 0;

}
