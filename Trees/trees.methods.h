# include "trees.h"

// Get a level of a try by (minimized) depth ala Dijkstra.
// In a tree the distance is ALWAYS minimized since each node has only one node above. This makes our work much easier since we don't have to check the depth really.
// On the first round (level = 0), lastLayer should contain the root of the desired tree. This will be done by `_getLevel`.
// This is useful for bredth first searches
Queue* _getLevel( Queue* lastLayer, int level, int objective ){
	
	if ( level == objective ){ return lastLayer; }

	// Add children of nodes in this layer to the queue
	// Once a nodes children are added, pop it
	QueueNode* active;
	QueueNode* stop = lastLayer -> end;
	
	do {
		
		active = lastLayer -> front;

		// add next layer to queue
		if ( active -> value -> left ){ 	queue(lastLayer, active -> value -> left);
		}
		if ( active -> value -> right){		queue(lastLayer, active -> value -> right);
		}

		// Point active to next in line. Do not free node because will like to use later.
		dequeue( lastLayer );
	
	} while ( active != stop );

	// Recurse now that lastLayer is the current layer.
	return _getLevel( lastLayer, level + 1, objective );

}
// Wrapper for the recursion.
Queue* getLevel( Node* tree, int layer ){

	Queue* firstLayer = newQueue( tree );
	_getLevel( firstLayer, 0, layer );

	return firstLayer;
}

// Use the _getLevel Recursion to determine height.
int getHeight( Node* tree ){

	Queue* layer = newQueue( tree );
	int k = 0;
	while( true ){
		if ( ! layer -> front ){
			return k;
		}
		layer = _getLevel( layer, k, k + 1);
		k++;
	}

	return -1;

}
