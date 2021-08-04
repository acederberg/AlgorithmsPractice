# include<memory>

# ifndef SINGLENODE
# define SINGLENODE

        struct Node{

                char*           value;
		struct Node*	before;
                struct Node*    after;

        };

        typedef struct Node Node;


        Node* newNode(const char* value, Node* before, Node* after){

                Node* N = (Node *)malloc( sizeof(Node) );

                N -> value = (char *)value;
		N -> before = before;
                N -> after = after;

                return N;
        }
        Node* newNode(const char* value){
                return newNode( value, (Node *)NULL, (Node *)NULL );
        }
        void destroy(Node* N){
                // N -> value will be freed automatically since not `malloc`
                free(N);
        }
        void show(Node* N, const char* endchar){
                // If passed nullptr will crash, annoying
                if ( !N ){ return; }
                // What do if not null
                printf("%s@%p ", N->value, (void*)N);
                // if(N->after){ printf(", next = %p ", (void *)N->next); }
                printf("%s", endchar);
        }
        void show(Node* N){ show(N, "\n"); }
        Node* end(Node *N){
                // Find the end of the linked list. Grows linearly.
                Node* out = N;
                while( out->after ){
                        out = out->after;
                }
                return out;
        }
	Node* start(Node *N){
		Node* out = N;
		while( out->before ){	
			out = out->before;
		}
		return out;
	}
# endif
