[Flattening a Binary Tree]( https://github.com/kovidgoyal/kitty/issues/856 )

The goal here is to take a binary tree and flatten it from top to bottom, and for each level from right to left. I have already implemented a similar method in the `Tree` subproject's `trees.tests.c` file's `flatten` method. The method used here is basically the bredth first search version of that. We can enumerate all of the layers by remembering the where the first and last nodes of the previous were, and then listing their idvidual children left to right and repeating. E.g. for

		1
	       / \
	      2   3
             / \
	    4   5
               / \
	      6   7

would start with root, then we append roots left child and right child. We would have to save the position of the first of the new layer so that we may continue to enqueue more. At this point

	[1, 2, 3]
	 ^
	 t0, s0*

We must remember that layer 1 starts at index  1 (root is layer 0). To know when to stop, we should record the index of the final node of layer 1 (2). Next look at the node located at index 1. This node has a left child and a right child. The next node has none. Thus at this point the queue looks like

	[1,  2,  3,  4,  5]
             ^   ^
             t1  s1

This will get us to an index of 4 since we have added two nodes. We now inspect the children of node 4 to realize that there are none. Next we enqueue the rightmost element of node 5:

	[1,  2,  3,  4,  5,  6,  7]
                     ^   ^
		     t2  s2

and this completes our process. 

* tk marks the first node of the kth layer and sk marks the final node of the same layer. This is the range of nodes searched in the above step.
