# include <memory>

// The graph represented by DUMMY
//	
//     [1]---3---[4]--------+
//	|         |   	    |
//	5         |         |
//	|         |         |
//     [2]-------[3]-------[5]

int DUMMY[5][5] = {
	{ 0,  5,  0,  3,  0 },
	{ 5,  0,  1,  0,  0 }, 
	{ 0,  1,  0,  1,  1 },
	{ 3,  0,  1,  0,  1 },
	{ 0,  0,  1,  1,  0 }
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
	show(distances);
	return distances;
}

int*
// SOLVER
int* solve(){

	// The `k`th distance will be the `k`th value of `distances`. Weather a node has been used or not is determined by used.
	// Track the index with the minimum distance from the previous node using best.
	bool used[ size ] = {0, 0, 0, 0, 0};
	used[ start ] = 1;

	int* distances = makeDistances();
	int best = 0;

	// Check layer around start
	for (int k = 0; k < size; k++){
		
		if ( used[k] == 0 && DUMMY[0][k] ){

			
			// If a distance is not set (when distance is `-1`) set it.
			
			if ( distances[k] == -1 ){ distances[k] = DUMMY[0][k]; }
			if ( distances[k] < distances[best] || best == 0){
				printf("HERE\n");
				best = k;
			}
			
			printf("k = %i, distances[k] = %i\n", k, distances[k]);	

			
		}

	}
	printf("best = %i\n", best);	
	used[ best ] = 1;
	// Best should be reset on each turn. best is the index of the starting node for the next term.
	best = 0;
	

	return distances;

}

int main(){
	
	int* distances = solve();
	show(distances);

	return 0;
}
