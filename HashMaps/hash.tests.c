# include "hash.h"


void testHashMapping(Hash* H, const char* C){

	printf( "hash(%s) = %i\n", C, hash(H, C) );

}
void testHashMapping(){

	Hash* H = newHash(10);
	testHashMapping(H, "foo");
	testHashMapping(H, "bar");
	testHashMapping(H, "Spam");
	testHashMapping(H, "spam");

}
void testNode(){
	
	Node* N = newNode("foo", NULL);

}

int main(){

	testNode();
	return 0;

}
