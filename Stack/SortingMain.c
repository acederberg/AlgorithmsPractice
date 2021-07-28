# include "Sorting.h"

int test_naiveSort(){

	Stack* S = newStack(5);
	push(S, 2);
	push(S, 5);
	push(S, 3);
	push(S, 8);
	push(S, 14);
	show(S, 1);
	
	// Sort the underlying memory
	naiveSort(S);
	show(S, 1);
	
	return 0;

}

void test_smartSort(){
	
	Stack* S = newStack(6);
	push(S, 4); push(S, 1); push(S, 5); push(S, 3); push(S, 6); push(S, 2);
	//show(S, 1);

	Game* G = newGame(S);
	show(G,1);
	push( G -> game[1], 4);

	printf( "\nempty = %i", fillWith(G, 2) ) ;
//	show(G -> game[0], 0);
//	show(G -> game[1], 0);
//	show(G -> game[2], 0);

}
int main(){

	test_smartSort();
	return 0;

}

