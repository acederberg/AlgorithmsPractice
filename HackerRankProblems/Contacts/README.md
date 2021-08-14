# [Contacts](https://www.hackerrank.com/challenges/contacts/problem)

## Synopsis

The goal here is to create an application to add contacts to some data structure. The application must do the following:

1. Add a name.
2. Find names from fragments of a name. Return how many there are. 

It appears that the name framents we are to be concerned with are only begginings, but these problems are never precise about such things.

## Implementation

This might be a good time to use a BST. We would do this by alphabetization. E.g. if we have a queue of names edd, edward, eddy, ed, edwin, edwina, frank, and john, then the tree would look like

	          edd
	         /   \
	        ed    edward  
                     /      \
	           eddy     edwin
			         \
                                edwina --- frank --- john
	                      

since the alphabetization of the queue is 

	ed
	edd
	eddy
	edward
	edwin

Then we will search the tree for first branch with a name fragment and count the number of children which contain that fragment. That is, reduce size of search pool, then search the reduced pool.
