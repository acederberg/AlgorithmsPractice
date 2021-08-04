# include<memory>

# ifndef SINGLENODE
# define SINGLENODE

        struct Node{

                char*           value;
                struct Node*    next;

        };

        typedef struct Node Node;


        Node* newNode(const char* value, Node* next){

                Node* N = (Node *)malloc( sizeof(Node) );

                N -> value = (char *)value;
                N -> next = next;

                return N;
        }
        Node* newNode(const char* value){
                return newNode(value, (Node *)NULL);
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
                // if(N->next){ printf(", next = %p ", (void *)N->next); }
                printf("%s", endchar);
        }
        void show(Node* N){ show(N, "\n"); }
        Node* traverse(Node *N){
                // Find the end of the linked list. Grows linearly.
                Node* out = N;
                while( out->next ){
                        out = out->next;
                }
                return out;
        }

# endif
