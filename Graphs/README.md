[Notes on Dijkstra's Algorithm] (https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)

Roughly speaking, one starts at a node in a graph, considers the weight to move forward in an attempt to enumerate all of the shortest paths to vertices in the graph from the initial node. The edges of the graph are colored using integers. This means that we map the graph onto an uncolored tree giving us the path options, e.g.

	[1] ----10----- [2] ----2----- [5]
	 |	        /		|
	 |             /		|
	 |     	      /			|
	 3   ----4---/			12
	 |  /				|
	 | /				|
	 |/	      			|
	[4] ----1----------------------[3]


would on the first step be

	[1](0) --------> [4](3)

since we have not used the node `[4]` and have not updated the graph. Here the number in parenthesis is the minimized distance from `[1]`.

	*1* ----10----- [2] ----2----- [5]
	 |	        /		|
	 |             /		|
	 |     	      /			|
	 3   ----4---/			12
	 |  /				|
	 | /				|
	 |/	      			|
	*4* ----1----------------------[3]

where the started nodes represent the used nodes. We can now determine (minimum) distances from the intial node and nodes `[2]` and `[3]` by taking the sum of the edge values, e.g.

	+-----------------------+-----------------------+
	|	end point 	|	distance*	|
	+-----------------------+-----------------------+
	|	[4]		|	3		|
	|	[2]		|	7		|
	|	[3]		|	4		|
	|			|			|
	+-----------------------+-----------------------+	
	*distance is the minimum value by traversing the path made so far.

since the vertex `[3]` has minimum distance we will update the tree using it:

	[1](0) --------> [4](3)--------> [3]
	
from the ends of out tree, we see that it is easier to go from `[4]` to `[2]` than it is to go from `[2]` to `[5]`, thus we add lesser to the tree:

	[1](0) --------> [4](3) --------> [3](4)
			|
			|
		       [2](7)

Finally we see that going from `[2]` to `[5]` (distance 9) is easier than going from `[3]` to `[5]` (distance 15), consisely

	[1](0) --------> [4](3) --------> [3](4)
			|
			|
		       [2](7) --------> [5](9)

is our final minimized distance tree. This summarized a few rules:
	
	1. When traversing this particular graph from `[1]`, never go from `[1]` to `[2]` and never from `[3]` to `[5]`
	2. Only go from `[2]` to `[5]` if trying to get to `[5]`.
	3. Only go from `[4]` to `[3]` if the desired endpoint is [3]. 

This gives us an idea of the most efficient way to traverse the graph.

# The Adjacency Matrix 

**Definition**: An adjacency matrix is a matrix representing a finite graph. The index (i ,j) represents the color of the edge between verices `v_i` and `v_j` where a graph is a set of vertices `G = {v_i | i is less than some n > 0 }`, a relation `~` such that `v_i ~ v_j` if and only if there is an edge between them, and a map `Phi(i, j) = weight of vertex from i to j iff v_i ~ v_j else 0`. That is, we can give the adjacency matrix as `[ Phi(i,j) ]` where `i` and `j` are in `1, ..., n`. For the above example we end up with the following matrix:

	0	10	0	3	0
	10	0	0	4	2
	0	0	0	1	12
	3	4	1	0 	0
	0	2	12	0	0

Directed graphs will have antisymetric adjacency matrices and undirected graphs have symetric mattrices.
