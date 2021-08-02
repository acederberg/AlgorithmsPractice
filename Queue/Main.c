#include "Queue.h"


int main(){


	Node* N = newNode( "fake" );

	Queue* Q = newQueue(N);
	
	show(Q->last);
	show(Q->last->next);

	return 0;

}
