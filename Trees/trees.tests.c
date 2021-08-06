// Tests for the structures and fundimental methods in `trees.h`. Extended methods will be included in `treemethods.h`

# include "trees.h"

Node* testNode(){

	Node* N = newNode(0);
	insert(N, 1);
	insert(N, 2);

	insert(N -> left, 3);
	insert(N -> left, 4);
	insert(N -> left -> left, 5);
		
	return N;
}

void testQueueRecurser(Queue* Q, Node* tree){
	
	// If a node exists to the left, add it and it's children to the queue.
	if ( tree -> left ){
		
		queue( Q, tree -> left );
		testQueueRecurser( Q, tree -> left );
	}
	// If a node exists to the right, add it and it's chilren to the queue.
	if ( tree -> right ){

		queue( Q, tree -> right );
		testQueueRecurser( Q, tree -> right );
	}

}

Queue* testQueue(Node* tree){

	// Make Q for 	
	Queue* Q = newQueue( tree );
	testQueueRecurser( Q, tree );
	return Q;

}

int main(){

	// Create a new tree.
	Node* N = testNode();
	show(N);

	// Crush whole tree into Queue using recursion.
	Queue* Q = testQueue( N );
	show(Q);

	while ( Q -> front ){
		QueueNode* D = dequeue( Q );
		show( Q );
		free( D );
	}	



	return 0;


}

