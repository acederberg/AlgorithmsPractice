# include<memory>
# include<stdio.h>

# ifndef STACK
# define STACK

	struct Stack{
		int capacity;
		int index;
		int* memory;
	};

	typedef struct Stack Stack;

	// Should probably worry about wrapping.
	// See this: https://wiki.sei.cmu.edu/confluence/display/c/MEM07-C.+Ensure+that+the+arguments+to+calloc%28%29%2C+when+multiplied%2C+do+not+wrap
	Stack* newStack(int capacity){

		// Malloc space so not destroyed.
		Stack* S = ( Stack * )malloc( sizeof(Stack) );

		S -> capacity = capacity;
		S -> index = -1;

		// Point memory to some malloced space somewhere. Calloc used to initialize the memory.
		S -> memory = (int *)calloc( (capacity + 1), sizeof(int) );

		return S;
	}

	void show(Stack* S, bool header){

		if (header){
			printf(
				"capacity = %i\tindex = %i\t",
				S -> capacity,
				S -> index
			);
		}

		printf("values = (");
		int* temp = S -> memory;
		while(1){

			if (!*temp){
				printf(")\n");
				break;
			}
			else{
				printf("%i, ", *temp );
			}
			temp++;

		}

	}

	void mem(Stack* S){
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
		bool out = S->index < S->capacity;

		if (out){
			S -> index++;
			S -> memory[S->index] = k;
		}

		return out;

	}

	bool pop(Stack* S){

		bool out = !(S->index < 0);

		if (out){
			// Nullify because important for looping. Decrement.
			S -> memory[S->index] = ( int )NULL;
			S -> index--;
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

# endif

//----------------------------------------------------------------------------//
// More features. Methods which go beyond the default methods but who extend the functionality of the stack without returning a stack.

# ifndef SUPER
# define SUPER

	// Templates
	void resize(Stack *S);

	// Functions
	int between(Stack *S, int min, int max);
	void clear(Stack *S){ while( pop(S) ){} }
	int count(Stack *S, int value);
	void insert(Stack* S, int position, int value);
	void push(Stack* S, int* array, int length){
		// Grows linearly with the size of length.
		int k = 0;
		int* temp = array;
		while (k < length){
			if ( !push(S, *temp) ){
				printf("\nExpanding stack -- continuing to insert values. Resized S:\n ");
				resize(S);
				printf("\n");
				continue;
			}
			temp++;
			k++;
		}

	}
	void remove(Stack *S, int position);
	void resize(Stack *S){
		// Constant time complexity.
		// Save old capacity for initialization after realloc.
		int old = S -> capacity;
		S -> capacity = 2 * old;
		S -> memory = ( int * )realloc( S -> memory, S->capacity * sizeof(int) );

		// Initialize because realloc doesn't.
		for (int k = old + 1; k < S->capacity; k++){ S -> memory[k] = ( int )NULL; }

	}

# endif