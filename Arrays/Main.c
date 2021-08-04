# include "Array.h"

void test_newArray(bool test_destroy){

        printf("\nGenerating a new array...\n");
        Array* A = newArray(8);

        set(A, 0, 1);
        show(A);

        printf("\nFilling with fibbonichi numbers...\n");
        int k = 0;
        int value = 1;

        // Recall that set returns false once out of bounds.
        while( set(A, k + 1, value ) ){
                show(A);
                value =  A->memory[k ]+ A->memory[k+1];
                k++;
        }

        printf("\nDestructively inserting a few values...\n");
        insert(A, 3, 303);
        insert(A, 3, 404);
        insert(A, 3, 505);
        show(A);

        printf("\nRemoving a few values...\n");
        remove(A, 1);
        //remove(A, 2);
        //remove(A, 3);

        printf("\nInserting values to test count...");
        insert(A, 6, 1);
        insert(A, 7, 1);
        show(A);

        printf("\nNumber of `1`s in array = %i.\n", count(A, 1) );
        printf("\n(Number of entries between 0 and 10) = %i.\n", count(A, 0, 10) );

	printf("\nSorting A... A = \n ");
	naiveSort(A);
	show(A);

        printf("\nDestroying A. Will attempt to show post destroy.\n");
        destroy(A);

        if (test_destroy){
                show(A);
        }
}

int main(){

        test_newArray(false);
        return 0;

}
