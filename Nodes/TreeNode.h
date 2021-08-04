# include<memory>

# ifndef SINGLENODE
# define SINGLENODE

        struct Node{

                char*           value;
                struct Node*	left;
		struct Node* 	right;

        };

        typedef struct Node Node;


        Node* newNode(const char* value, Node* left, Node* right){

                Node* N = (Node *)malloc( sizeof(Node) );

                N -> value = (char *)value;
                N -> left = left;
		N -> right = right;

                return N;
        }
        Node* newNode(const char* value){
                return newNode( value, (Node *)NULL, (Node *)NULL );
        }
        void destroy(Node* N){
                // N -> value will be freed automatically since not `malloc`
                free(N);
        }
        void show( Node* N, const char* endchar ){
                // If passed nullptr will crash, annoying
                if ( !N ){ return; }
                // What do if not null
                printf("%s@%p ", N->value, (void*)N);
                if( N->left ){ printf(", left = %p ", (void *)N->left); }
                if( N->right ){ printf(", right = %p ", (void *)N->right); }
                printf("%s", endchar);
        }
        void show( Node* N ){ show(N, "\n"); }
        Node* traverse( Node *N, Node* (*next)(Node*) ){
                // Find the end of the linked list. Grows linearly.
                Node* out = N;
                do {
                        out = next( out );
                }
		while ( out );

                return out;
        }

# endif
