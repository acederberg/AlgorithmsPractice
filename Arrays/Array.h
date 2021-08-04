# include<memory>
# include<stdio.h>

# ifndef ARRAY
# define ARRAY

        // Struct, Typedef, and constructors.
        struct Array{
                // Could get away without this, but I like length so that 0s can go in.
                int* memory;
                int capacity;
        };
        typedef struct Array Array;

        Array* newArray(int capacity){

                Array* A = (Array *)malloc( sizeof(Array) );
                A -> memory = (int *)calloc( capacity, sizeof(int) );
                A -> capacity = capacity ;

                return A;

        }

        // Prototypes
        void show(Array*);


        int count(Array* A, int min, int max){
                // Another algorithm with linear growth. Roughly exactly the same as the above, not sure how to design around this.

                int count = 0;
                int* temp = A -> memory;
                while( 1 ){
                        if ( !*temp ){ break;
                        } else if( *temp < max & min < *temp ){
                                count++;
                        }
                        temp++;
                }
                return count;

        }
        int count(Array* A, int value){

                // Grows linearly with list size since the number of turns the while loop does is exactly the stack capacity.
		int out = 0;
		int* temp = A -> memory;
		while( 1 ){

			if ( !*temp ){ return out;
			} else if( *temp == value ){ out++; }
			temp++;

		}

        }
        void destroy(Array* A){

                free(A -> memory);
                free(A);

        }
        void insert(Array* A, int position, int value){
                // Destructive insertion. Overrides terminating value.
                int k = A -> capacity - 1;
                do {
                        A -> memory[k+1] = A -> memory[k];
                        k--;
                }
                while ( !(k < position) );

                A -> memory[position] = value;
        }
        void remove(Array* A, int position){
                // Should try only using push and pop.
                // Grows linearly like push.

                //initialize value to be brought in finally.
                A -> memory[ A->capacity ] = ( int )NULL;

                int k = position;
                do {
                        A -> memory[k] = A -> memory[k+1];
                        //show(A);
                        k++;
                } while ( !(k > A->capacity) );

        }

        bool set(Array* A, int position, int value){
                if ( !(position < A->capacity) ){ return false; }
                A -> memory[position] = value;
                return true;
        }

        void show(Array* A){

                printf("(");
                int* temp = A -> memory;
                int k = 0;
                while(k < A->capacity){
                        printf("%i, ", A -> memory[k]);
                        k++;
                }
                printf(")\n");

        }
	// Sort in-place the memory array.
	void naiveSort(Array *S){
		
		int temp;

		for (int k = 0; !(k > S->capacity) ; k++ ){
			for(int j = 0; j < k; j++){
			
				if ( S->memory[j] < S->memory[k] ){
					temp = S -> memory[k];
					S -> memory[k] = S -> memory[j];
					S -> memory[j] = temp;
				}

			}
		}

	}


# endif
