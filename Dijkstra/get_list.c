# include <memory>

// Useful debug tool
void show(int* distances){
	printf("[ ");
	for ( int k = 0; k < 5; k++ ){
		printf("%i, ", distances[k] );
	}
	printf("]\n");
}

int* makeDistances(int size){
	// Initializing distances this way so that we can return distances.
	int* distances = ( int * )malloc( sizeof(int) * size );
	for ( int k = 0; k < 5; k++ ){ distances[k] = -1; }
	return distances;
}

// SOLVER
int* solve(int ARR[5][5], int start, int size){

	// The `k`th distance will be the `k`th value of `distances`. Wether a node has been used or not is determined by used.
	// Track the index with the minimum distance from the previous node using best. Undefined distances are negative one.
	bool used[ size ] = {0, 0, 0, 0, 0};
	used[ start ] = 1;
	int* distances = makeDistances(size);
	distances[start] = 0;
	
	// Loop updatables. Add tracks distance already traversed. current_best is the index of the active node. best is the means by which we will get the next `current_best`.
	// Best starts at `-1` since that is not a usable index.
	int best = -1;
	int add = 0;
	int current_best = start;

	// Loop until all are used or stuck
	int j = 0;
	while ( j < size ){
		// Check layer around start
		for (int k = 0; k < size; k++){
			
			if ( used[k] == 0 && ARR[current_best][k] ){
				// If a distance is not set (when distance is `-1`) set it.
				if ( distances[k] == -1 ){ 
					distances[k] = ARR[current_best][k] + add; 
				}
				// If best is not positive or zero, then set best.
				if ( best < 0 ){ 
					best = k;			
				// If best is already positive.
				} else if ( ARR[current_best][k] < distances[best] ){
					best = k;
				       	distances[best] = ARR[current_best][k] + add;
				}
			}

		}
		// Mark best as used.
		// `best` should be saved into current_best (active node index) and reset. `add` acounts for this distance traversed between start and active.  
		used[ best ] = 1;
		current_best= best;
		add = distances[best];
		best = -1;

		j++;
	}
	
	return distances;

}

void test1(){

	// The graph represented by DUMMY
	//	
	//     [0]---3---[3]----89--+
	//	|         |   	    |
	//	5         21        |
	//	|         |         |
	//     [1]--13---[2]-------[4]

	int DUMMY[5][5] = {
		{ 0,  5,  0,  3,  0 },
		{ 5,  0,  13, 0,  0 }, 
		{ 0,  13, 0,  21, 1 },
		{ 3,  0,  21, 0,  89},
		{ 0,  0,  1,  89, 0 }
	};
	int start = 0;
	int size = 5;

	int* distances = solve(DUMMY, start, size);
	show(distances);

}

int main(){

	test1();
	return 0;

}
