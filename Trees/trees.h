// Fundimental Tree and Queue. For derived methods, see `tree.methods.h`
# include<stdio.h>
# include<memory>

# ifndef TREE
# define TREE

	typedef struct treenode
	{
		int value;
		struct treenode* left;
		struct treenode* right;		

	} Node;

	Node* newNode(int value, Node* left, Node* right)
	{

		Node* node = ( Node * )malloc( sizeof(Node) );
		
		node -> value = value;
		node -> left = left;
		node -> right = right;
		
		return node;

	}
	Node* newNode(int value){
		
		return newNode(
    			value,
			( Node * )NULL,
			( Node * )NULL
		);

	}
	
	bool insert( Node* base, int value ){

		if ( !base ){ printf("WARNING: Could not insert node on NULL\n"); return false; }

		Node* N = newNode(value);

		if ( !base -> left ){
	
			base -> left = N;
			return true;

		}
		else if( !base -> right) {

			base -> right = N;
			return true;

		}
		else {

			printf("WARNING: Could not inser node on full node at %p", base);
			return false;

		}
	}

	// Helper for show.
	char* getIndent(int depth){

		char* out = ( char * )calloc( depth, sizeof(char) ); 

		int k = 0;
		while ( k < depth ){

			out[k] = '\t';
			k++;

		}

		return out;
	}
	// Recursive show.
	void show( Node* base, int depth ){

		char* D = getIndent(depth);

		printf("%sBRANCH\n%s\tValue = %i\n%s\tLocation = %p\n", D, D, base -> value, D, base);
		
		// Show nodes to left if exist, then right if exist.
		if ( base -> left ){
			
			printf("%s\tLeft:\n", D);
			show(base -> left, depth + 2);

		}
		if ( base -> right ){	
	
			printf("%s\tRight:\n", D);
			show(base -> right, depth + 2);

		}
		
		printf("%sENDBRANCH\n", D);
		
		free(D);
	}
	// Overload so I don't need to put in depth = 0 ever damn time.
	void show( Node* base){ show(base, 0); }


# endif

# ifndef QUEUE
# define QUEUE
	
	// =============================//

	// Use queue to keep track of the various other parts of algorithms, for instance the Nodes used in dijkstras algorithm.
	typedef struct queuenode
	{
		Node* value;
		struct queuenode* next;
	
	} QueueNode;
	
	// Create a new queue node. Should never have to use this directly, just use the overloaded methods on treenodes.
	QueueNode* newQueueNode(Node* value, QueueNode* next)
	{
		QueueNode* Q = ( QueueNode * )malloc( sizeof(QueueNode) );
		Q -> value = value;
		Q -> next = next;

		return Q;
	}

	// =============================//

	typedef struct Queue
	{
		QueueNode* front;
		QueueNode* end;

	} Queue;

	// Create a queue from either a `QueueNode` or a `Node` which will have a queuenode made for it.
	Queue* newQueue(QueueNode* Q)
	{
		Queue* R = ( Queue * )malloc( sizeof(Queue) );
		R -> front =  Q;
		R -> end = Q;

		return R;
	}
	Queue* newQueue(Node* N){
		return newQueue(
			newQueueNode(N, NULL)
		);
	}
	
	QueueNode* dequeue( Queue* R ){
	
		// Save a pointer to the queue node before updating. This will be returned.
		QueueNode* out = R -> front;
		
		// Set front to the next in line.
		// If front and end are the same, set both to null so that we can know that the queue is mt
		if ( ! R -> front -> next ){
			R -> front = NULL;
			R -> end = NULL;
		}
		else{
			
			R -> front =  R -> front -> next;
		}

		// Return out so that the user can decide what to do with it instead of just freeing it.
		return out; 
		
	}	
	
	// `Show` method
	void show( QueueNode* Q ){

		printf("%i@%p",  Q -> value -> value,  Q -> value );
		if ( Q -> next ){ printf(" <= "); show( Q -> next ); }
		else{ printf( ".\n" ); }

	}
	void show( Queue* R ){
	
		if ( R -> front ){ show( R->front ); }
		else{ printf("EMPTY QUEUE"); }
	}

	// So that a QueueNode may be queued or a we pass a node to create a QueueNode pointing to it in the queue.
	void queue( Queue* R, QueueNode* Q ){

		R -> end -> next = Q;
		R -> end = Q;

	}

	void queue( Queue* R, Node* N){ queue( R, newQueueNode(N, ( QueueNode * )NULL ) );
			
	}
# endif


