# [Inserting Nodes into a Binary Search Tree](https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem?isFullScreen=false&h_r=next-challenge&h_v=zen )

This one is precisely what it sounds like. Recall that in binary search trees we use the following insertion algorithm. Start with the root and a node to be inserted. If the color of that is greater than the color of the root, put it on the right, otherwise put it on the left if it is not the same value as root. If the node in the desired direction is filled, then do the same process at that node and continue to recurse. Suppose we have a queue of values to insert,

	[3, 7, 1, 2, 6, 2]

and the initial node is 5. The first value is 3 - this will go to the left of 5. The next value is 7. 7 is greater than 5, thus we insert 5 to the right and subsequently pop 7 from the queue. Our tree and values are now

		5
               / \
              3   7

	[1, 2, 6, 4]

1 is now in front. 1 is greater than 5, so we go left of 5 to 3. 1 is less than 3 so it goes to the left of three. 2 will also be less than 5 but is less than 3 so it can't go there. We go to our only option, 1 -- since 2 is greater than 1 we put it on the right side. Now

		5
               / \
              3   7
	     /
            1
             \
              2

	[6, 4]

6 is greater than 5, so we go to the right to 7. Since 6 is less than 7, we put it on the left of 7. 4 is less than 5, so we move to 3. Since 4 is greater than 3 we go to the right of 3. Hence our final solution is

		+-- 5--+
               /        \
              3   	 7
	     / \ 	/
            1   4      6 
             \
              2

	[]


		
