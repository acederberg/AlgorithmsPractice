# include <stdio.h>
# include <memory>

# ifndef LIST
# define LIST 

	// Single linked list.
	typedef struct node{

		int value;
		struct node* next;

	} Node;

	Node* newNode( int value, Node* next ){

		Node* N = ( Node * )malloc( sizeof( Node ) );
		N -> value = value;
		N -> next = next;

		return N;
	}

	void insertAfter( Node* N, int value){
		// Create a new node that points to the N->next if it exists, otherwise point to null.
		// Sexy, sexy ternary.
		Node* M = newNode( value, N->next ? N->next : NULL );
		// Make M after N
		N->next = M;
	}

	void insertAfter( Node* N, Node* M){
		if ( N -> next ){
			Node* O = N->next;
			N -> next = M;
			M -> next = O;
		}
		N -> next = M;
	}

	Node* split( Node* N ){
		// Get return value, cut after `N`.
		Node* M = N -> next;
		N -> next = NULL;
		// Return segment head
		return M;
	}

	void show( Node* N ){
		printf("%i@%p", N -> value, ( void* )N );
		if (N->next){ 
			printf(" -> "); 
			show( N -> next );
		}
		else { printf(".\n"); } 
	}

	Node* newList( int* values, int length){
		
		// Create head, pointer to end for loop.
		Node* N = newNode( values[0], NULL );
		Node* temp = N;

		// Insert node after end, increment `temp`.
		for( int k = 1; k < length; k++ ){
			insertAfter( temp, values[ k ] );
			temp = temp -> next;
		}

		// Return the head.
		return N; 

	}

# endif
