# include "list.h"

void test_list(){

        Node* N = newNode(1, NULL);
        insertAfter(N, 2);
        show( N );

        printf("\nSplitting...\n");
        Node* M = split( N );
        show( N );
        show( M );

}

void test_new_list(){

        int data[] = {1,1,2,3,5,8,13,21,34,55};
        Node* head = newList(data, 10);
        show( head );
}

int main (){

        test_new_list();
        return 0;

}
