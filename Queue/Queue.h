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
		
		free(N ->value);
		free(N);

	}
	void show(Node* N){
		
		printf("%s@%p ", N->value, (void*)N);
		if(N->next){ printf(", next = %p ", (void *)N->next); }

	}
	Node* traverse(Node *N){
		// Find the end of the linked list. Grows linearly.
		Node* out = N;
		while( out->next ){
			out = out->next;
		}
		return out;
	}

	
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

	}
	void show(Queue* Q){

		Node* temp = Q -> first;
		while( temp -> next ){
			
			show(temp);
			printf(" => ");
			temp = temp -> next;

		}
		destroy(temp);
		printf("\n");
	}
# endif
