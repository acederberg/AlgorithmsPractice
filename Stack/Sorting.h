# include "Stack.h"

# ifndef STACKSORT
# define STACKSORT

// Sort in-place the memory array.
void arraySort(Stack* S){
	
	int temp;

	for (int k = 0; !(k > S->index) ; k++ ){
		printf("\n-----------------------\nk = %i\n", k);
		for(int j = 0; j < k; j++){
		
			printf("j = %i\t", j);
			if ( S->memory[j] < S->memory[k] ){
				printf("Sorting\t");
				temp = S -> memory[k];
				S -> memory[k] = S -> memory[j];
				S -> memory[j] = temp;
			}

		}
	}

}

# endif
