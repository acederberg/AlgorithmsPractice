# include<memory>
# include<stdio.h>

# ifndef STACK
# define STACK
	
	// STRUCT, TYPEDEF, PROTOTYPES.
	struct Stack{
		int capacity;
		int index;
		int* memory;
		int* top;
	};

	typedef struct Stack Stack;

	bool pop(Stack*);
	bool push(Stack*, int);
	void show(Stack*, bool);

	// Should probably worry about wrapping.
	// See this: https://wiki.sei.cmu.edu/confluence/display/c/MEM07-C.+Ensure+that+the+arguments+to+calloc%28%29%2C+when+multiplied%2C+do+not+wrap
	Stack* newStack(int capacity){

		// Malloc space so not destroyed.
		Stack* S = ( Stack * )malloc( sizeof(Stack) );

		S -> capacity = capacity;
		S -> index = -1;

		// Point memory to some malloced space somewhere. Calloc used to initialize the memory.
		S -> memory = (int *)calloc( (capacity + 1), sizeof(int) );
		S -> top = NULL;
		return S;
	}

	Stack* copy(Stack * S){
		Stack* T = newStack( S->capacity );
		int k = 0;
		while( push( T, S -> memory[k] ) && k < S->index ){ k++; };
		return T;
	}

	void destroy(Stack* S){
		free( S-> memory );
		free( S );
	}

	void mem(Stack* S){
		show(S, 1);
		printf("mem:values = (");
		int k = 0;
		while ( k < S -> capacity ){
			printf("memory[%i]:\t%p\t=>\t%i\n", k, (void *)&S->memory[k], S->memory[k] );
			k++;
		}
	}

	bool push(Stack* S, int k){
		// Return true or false depending on success.
		// Append to the top of the stack depending if there is space. Will use bool return value to make an `autopush` function which will double the space allocated.
			S -> index++;
		bool out = S->index < S->capacity;

		if (out){
			S -> top = &( S -> memory[S->index] );
			*S -> top = k;
		}

		return out;

	}

	bool pop(Stack* S){

		bool out = !(S->index < 0);

		if (out){
			// Nullify because important for looping. Decrement.
			S -> memory[S->index] = ( int )NULL;
			S -> index--;
			S -> top = &( S -> memory[S->index] );
		}
		else{
			printf("HERE\n");
			S -> top = NULL;
		}
		return out;

	}
	bool pop(Stack* S, int how_many){
		bool* out;
		*out = 1;
		for(int k = 0; k < how_many; k++){
			*out &= pop(S);
			if (!out){ break; }
	       	}
		return *out;
	}
	
	void show(Stack* S, bool header){

		if (header){
			printf(
				"capacity = %i\tindex = %i\t",
				S -> capacity,
				S -> index
			);
			// Because when empty top is NULL
			if (S->top){ printf("*top = %i\t", *( S->top ) ); }
			printf("top = %p\n", S->top );
		}

		printf("values = (");
		int k = 0;
		while(1){

			if ( k > S->index ){
				printf(")\n");
				break;
			}
			else{
				printf("%i, ", S->memory[k] );
			}
			k++;

		}

	}


# endif

//----------------------------------------------------------------------------//
// More features. Methods which go beyond the default methods but who extend the functionality of the stack without returning a stack.

# ifndef SUPER
# define SUPER

	// Templates
	void resize(Stack *S);

	// Functions
	void clear(Stack *S){ while( pop(S) ){} }
	// Redunant count
	int count(Stack *S, int min, int max){
		// pop elements and count.
		Stack *temp = copy(S);
		int* count; *count = 0;
		while( pop(temp) ){
			if ( !(min > *temp->top) && !(max < *temp->top) ){ *count++; }
		}
		return *count;	
	};
	int count(Stack *S, int value){
		Stack *temp = copy(S);
		int k = 0;
		while( true ){
			if ( pop(temp) ){
				if ( *temp->top == value ){ k++; }
			}
			else{ return k; }
		}
		destroy(temp);
		return k;
	};
	void insert(Stack* S, int position, int value);
	void push(Stack* S, int* array, int length){
		// Grows linearly with the size of length.
		int k = 0;
		int* temp = array;
		while (k < length){
			printf("next value = %i\n", temp[0]);
			show(S, 1);

			if ( !push(S, *temp) ){
				printf("\nExpanding stack -- continuing to insert values. Resized S:\n ");
				show(S, 1);
				resize(S);
				printf("\n");
				continue;
			}
			printf("HERE");
			temp++;
			k++;
		}
		return;

	}
	void remove(Stack *S, int position);
	void resize(Stack *S){
		// Constant time complexity.
		// Save old capacity for initialization after realloc.
		int old = S -> capacity;
		S -> capacity = 2 * old;
		S -> memory = ( int * )realloc( S -> memory, S->capacity * sizeof(int) );
		// Initialize because realloc doesn't.
		for (int k = old ; k < S->capacity; k++){ 
			show(S, 1);
			S -> memory[k] = 0; 
		}
		
		// For some reason without this the compiler is upset.
		return;
	}

# endif
