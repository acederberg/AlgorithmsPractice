# include "Stack.h"

# ifndef SORTING
# define SORTING

Stack* newGolden(int size){
	
	Stack* S = newStack(size);
	push(S, 1);
	int last, before;
	last = 1;
	do{
		before = *S->top;

		if ( !( push(S, *S->top + last) ) ){ break; }
		last = before;
	}
	while( true );

	return S;
}

Stack* invert(Stack* S){

	Stack* temp = copy( S );
	Stack* T = newStack( S->capacity );
	
	while(temp -> top){
		push(T, *temp->top);
		pop(temp);
	}
	
	destroy(temp);
	
	return T;

}

bool is_ascending(Stack* S){
	
	Stack* temp = copy(S);
	show(temp, 1);
	int last;
       	last = *temp->top;
	pop(temp);

	do{
		if(temp->top){
			if ( !( last > *temp->top ) ){ 
				destroy(temp);
				return false; 
			}
			last = *temp->top;
		}
	}
	while( pop(temp) );

	destroy(temp);

	return true;
}

int empty(Stack** J){

	for( int k = 0; k < 3; k++ ){

		if ( !J[k] -> top ){return k; }

	}

	return -1;
}
int nonempty(Stack** J, int ignore){

	for( int k = 0; k < 3; k++){
		
		if ( k != ignore && J[k]->top ){ return k; }

	}

	return -1;
}
int exchange(Stack** J){

	int max = 0;
	int diff, sgn;
	int index;

	for (int k = 0; k < 3; k++ ){
		
		diff = *J[ k%3 ]->top - *J[ k%3 + 1 ]->top;
		sgn = ( diff>0 ) - (diff<0);	
			
		if ( diff * sgn > max ){ 
			max = diff;
			index = k;
		}
		
	}


	

}

void sort(Stack* S){

	Stack* J[3];
	J[0] = S;
	J[1] = newStack( S->capacity );
	J[2] = newStack( S->capacity );
	int mt = 1;
	int last = 0;
	int best = 0;

	while ( true ){
	
		
		if (mt > -1){ 
			
				
			move(J[ nonempty(J, mt) ], J[mt]); 

		}
		else{
			int max = exchange(J);	
			printf("max = %i", max);		
			break; 
		}
		mt = empty(J);

	    	printf("\n----------------------------------------------------------\n");
		for( int k = 0; k < 3; k++ ){ show(J[k], 0); }

	}
	destroy(J[1]);
       	destroy(J[2]);

}

# endif
