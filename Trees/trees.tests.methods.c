# include "trees.methods.h"

// Holy shit it actually works.
Node* getDummy(){

        // Layer 0
        Node* T = newNode(0);

        // Layer 1
        insert(T, 1);
        insert(T, 2);

        // Layer 2
        insert(T -> left, 3);
        insert(T -> left, 4);

        insert(T -> right, 5);

        // Layer 3
        insert(T -> left -> left, 6);
        insert(T -> left -> left, 7);

        insert(T -> left -> right, 8);
        insert(T -> left -> right, 9);

        insert(T -> right -> left, 10);

        // Layer 4
        insert(T -> right -> left -> left, 11);
        insert(T -> right -> left -> left, 12);

        return T;
}

void testLayers(Node* T){

	int k = 0;
	Queue* layer;
	while ( true ){

		layer = getLevel( T, k  );
		if ( layer -> front ){ 
			printf("\nlayer %i = \n", k);
			show( layer ); 
		}
		else{ break; }

		k++;

	}

}

void testGetHeight(Node* T){

	int N = getHeight( T );	
	printf("Height = %i", N );

}

int main(void){

	Node* T = getDummy();
	testLayers( T );
	testGetHeight( T );
	free( T );

	return 0;

}
