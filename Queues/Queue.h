# include<memory>

# ifndef QUEUE
# define QUEUE

	struct Node{
		
		char*		value;
		struct Node*	next;
		
	};

	typedef struct Node Node;


	Node* newNode(const char* value, Node* next){
		
		Node* N = (Node *)malloc( sizeof(Node) );

		N -> value = (char *)value;
		N -> next = next;

		return N;
	}
	Node* newNode(const char* value){
		return newNode(value, (Node *)NULL);
	}
	void destroy(Node* N){
		// N -> value will be freed automatically since not `malloc`
		free(N);
	}
	void show(Node* N, const char* endchar){
		// If passed nullptr will crash, annoying
		if ( !N ){ return; }
		// What do if not null
		printf("%s@%p ", N->value, (void*)N);
		// if(N->next){ printf(", next = %p ", (void *)N->next); }
		printf("%s", endchar);
	}
	void show(Node* N){ show(N, "\n"); }
	Node* traverse(Node *N){
		// Find the end of the linked list. Grows linearly.
		Node* out = N;
		while( out->next ){
			out = out->next;
		}
		return out;
	}

	//---------------------------------------------------------------------------------------------------------------------//

	struct Queue{

		Node* first;
		Node* last;

	};
	
	typedef struct Queue Queue;

	Queue* newQueue(Node* N){
			
		Queue* Q = (Queue *)malloc( sizeof(Queue) );
		Q -> first = N;
		Q -> last = traverse(N);



		return Q;

	}
	void queue(Queue* Q, const char* value){

		Q -> last -> next = newNode( value );
		Q -> last = Q -> last -> next;

	}
	void dequeue(Queue* Q){
		
		Node* temp = Q -> first -> next;
		destroy(Q -> first);
		show(Q -> first);
		Q -> first = temp;
		show(Q -> first);

	}
	void show(Queue* Q, const char* sepchar){

		Node* temp = Q -> first;
		
		if ( Q -> first ){ 
			printf("first = ");
			show(temp, "\t");
		}
		if ( Q -> last ){
			printf("last = ");
			show(Q -> last, "\n");
		}	
		while( temp -> next ) {	
			show(temp, sepchar);
			printf(" => ");
			temp = temp -> next;
		}
		
		show(temp);
		// Do not destroy, did not `malloc` for
		// destroy(temp);
		printf("\n");
	}
	void show(Queue* Q){
		show(Q, " ");
	}

# endif
