# include "Sorting.h"

int test_ascending(){

	Stack* G = newGolden(13);

	printf("is_ascending = %i", is_ascending(G) );
	
	pop(G);
	push(G,1);
	
	
	
	printf("is_ascending = %i", is_ascending(G) );


	return 0;

}
int main(){

	Stack *G = newGolden(13);
	show(G, 1);
	Stack* H = invert(G);
	destroy(G);
	show(H, 1);
	sort(H);
	return 0;

}
