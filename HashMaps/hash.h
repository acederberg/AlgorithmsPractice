# include <stdio.h>
# include <memory>

# ifndef HASH
# define HASH

	
	typedef struct HashNode{
		
		const char* value;
		HashNode* next;

	} Node;

	Node* newNode(const char* value, Node* next){

		Node* N = ( Node * )malloc( sizeof( Node ) );
		N -> value = value;
		N -> next = next;

		return N;

	}

	// Hash table from `const char*` to `const char*`.
	typedef struct HashTable{

		int size;
		Node** data;

	} Hash;

	Hash* newHash(int size){

		Hash* H = ( Hash * )malloc( sizeof( Hash ) );
		H -> size = size;
		H -> data = (Node** )malloc( size * sizeof( Node * ) );
		return H;
		
	}

	void destroy(Hash* H){

		free( H -> data );
		free( H );
		
	}

	int hash(Hash* H, const char * C){
		
		// Hashing based on sum of integer values of string modulus hash size. Bigger hashes will be faster.
		int output = 0;

		// Loop while waiting for `NULL`.
		const char* temp = C;
		while ( *temp ){
			output = output + ( int )*temp;
			printf( "%i\n", output );
			temp++;
		}
		
		return output % H->size;
	
	}

	





# endif
