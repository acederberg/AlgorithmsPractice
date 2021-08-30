# include "list.h"
//		printf("\nHERE\n");

Node* half(Node* arr){
	Node* temp = arr;
	Node* center = arr;
	while ( temp->next ){
		if ( temp -> next -> next ){
			temp = temp->next->next;
	       	}
		else{ 
			// since temp->next must exit we will cut its next.
			break ; 
		}
		center = center->next;
		
	}
	return split( center );
}

// Node* _sort(Node* arr){}





Node* sort(Node* arr){
	
	Node* center = half( arr );
	
	printf("\n-------------------------------\n");

	show( center );
	show( arr );

	// If either `arr` or `center` have no next, then the length is one.
	center = sort( center );
	arr = sort( arr );	

	// Take both lists, look at the heads, find the minimum. 
	// Start list using minimum.
	// Repeat
	//Node* head = arr->value < center->value ? arr : center;
	// Node* end;

	return arr;
}

void mergeSort(Node* arr){
	
	

	return;
	
}

void test_half(){

	int _arr[] = {2, 1, 3, 4, 7, 11, 18, 29, 47, 76};
	Node* arr = newList(_arr, 10);
	show( arr );

	Node* center = half( arr );

	show( center );
	show( arr );

}

int main(){
	
	int _arr[] = {2, 1, 3, 4, 7, 11, 18, 29, 47, 76};
	Node* arr = newList(_arr, 10);
	show( arr );

Node* head = sort( arr );
	show( head );
	return 0;
}


