#include "Queue.h"


Queue* makedummy(){


	Node* N = newNode( "I'll" );

	Queue* Q = newQueue(N);
	queue(Q, "take");
	queue(Q, "liveleak");
	queue(Q, "over");
	queue(Q, "linkedin");
	queue(Q, ".");


	return Q;

}

int main(){

	Queue* Q = makedummy();
	show(Q);

	dequeue(Q);

	show(Q);


	return 0;

}
