# include <memory>

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

// Useful debug tool
void show(int* distances){
	printf("[ ");
	for ( int k = 0; k < 5; k++ ){
		printf("%i, ", distances[k] );
	}
	printf("]\n");
}

int* makeDistances(){
	// Initializing distances this way so that we can return distances.
	int* distances = ( int * )malloc( sizeof(int) * size );
	for ( int k = 0; k < 5; k++ ){ distances[k] = -1; }
	return distances;
}

bool allupdated(bool* updated){
	// Make sure all elements are non-zero 
	// Would use summation since this design patter is disgusting, but pointers can be annoying in this situation.
	for ( int k = 0; k < 5; k++ ){
		if ( !updated[k] ){ return false; }
	}
	return true;
}
// SOLVER
int* solve(){

	// The `k`th distance will be the `k`th value of `distances`. Weather a node has been used or not is determined by used.
	// Track the index with the minimum distance from the previous node using best. Best starts at `-1` since that is not a usable index.
	bool used[ size ] = {0, 0, 0, 0, 0};
	used[ start ] = 1;

	int* distances = makeDistances();
	int previous_shortest = 0;
	int best = -1;
	int add = 0;
	int current_best = start;

	// Loop until all are updated
	int j = 0;
	while ( j < 4 ){
		printf("=========================================================\n");
		printf("current_best = %i\n\n", current_best);	
		printf("distances = \t");
		show(distances);
		
		// Check layer around start
		for (int k = 0; k < size; k++){
			
			if ( used[k] == 0 && DUMMY[current_best][k] ){
				printf("-----------------------------------------------------\n");
				printf("\t\tInspecting connection from %i to  %i...\n", current_best, k);
				printf("\t\tDistance between = %i\n", DUMMY[current_best][k] );

				// If a distance is not set (when distance is `-1`) set it.
				if ( distances[k] == -1 ){ 
					distances[k] = DUMMY[current_best][k] + add; 
					printf("\t\tSet distances[%i] =  %i\n", k, DUMMY[current_best][k]);
				}
				
				// If best is not positive or zero, then set best.
				if ( best < 0 ){ 
					printf( "\t\t%i < 0\n", best);
					best = k;			
				// If best is already positive.
				} else if ( DUMMY[current_best][k] < distances[best] ){
					best = k;
					printf("\t\t%i < %i. Setting distances[%i] = %i.\n", DUMMY[current_best][k], distances[best], best, DUMMY[current_best][k] );
				       	distances[best] = DUMMY[current_best][k] + add;
				}
			}

		}
		used[ best ] = 1;
		// Best should be reset on each turn. best is the index of the starting node for the next term.
		current_best= best;
		add = distances[best];
		best = -1;
		j++;
	}
	
	return distances;

}

int main(){
	
	int* distances = solve();

	return 0;
}
