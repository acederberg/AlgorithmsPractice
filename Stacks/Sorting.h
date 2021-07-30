# include "Stack.h"

# ifndef STACKSORT
# define STACKSORT

// Sort in-place the memory array.
void naiveSort(Stack* S){
	
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

// --------------------------------------------------------------

// Not necessary, but it useful. 
// Would be coold to sort using more than three. Could realloc.
struct Game{

	// Things well need to remember for the game.
	// Keep tract of empty columns, size, capacity, etc
	bool hasmt[3];
	int size;
	int capacity;
	int last; //index of the last moved column
	Stack* one;
	Stack* two;
	Stack* game[3];

};

typedef struct Game Game;

// Make a new Game struct
Game* newGame(Stack* S){

	Game* G = (Game *)malloc( sizeof(Game) );
	G -> last = 0;
	G -> hasmt[0], G -> hasmt[1], G -> hasmt[2] = true, false, false;
	G -> size = 3;
	G -> capacity = S-> capacity;
	G -> game[0] = S;
	G -> game[1] = newStack( S->capacity );
	G -> game[2] = newStack( S->capacity );
		
//	printf("size = %i\n", G -> size);
	
	return G;

}

void show(Game* G){
	for(int k = 0; k < G->size; k++){
		show( G -> game[k], 0 );
	}
}
// If a header arguement is given at all prints header. If true, prints headers for stacks
void show(Game* G, bool header){	
	printf("size = %i,\tlast = %p,\tcapacity = %i.\n", G->size, G->last, G->capacity);
	for(int k = 0; k < G->size; k++){
		show( G -> game[k], header );
	}	
}
void mem(Game* G){ for(int k = 0; k < G->size; k++){ mem( G -> game[k] ); }
}
int empty(Game* G){
	// return index of empty if exists else -1.
	for (int k = 0; k < G -> size; k++ ){	
		if ( G -> hasmt[k] ){ return k; }
	}
	return -1;
}
int fillWith(Game* G, int column){
	// column is the output of empty
	for(int k = 0; k < G -> size; k++){
		if ( k != column & k != G -> last ){
			return k;
			break;
		}
	}
	return -1;
}
void fill(Game* G, int column){
	// Rule two as in my notes
	fillWith( G, column );
}	
void move(Game* G, Stack* firstColumn, Stack* secondColumn){
	// Rule one as in my notes. `turn` will hold on to distances and determine firstcolumn and second column.
			
	return;
}
void turn(Game* G){

	return;
}
# endif
