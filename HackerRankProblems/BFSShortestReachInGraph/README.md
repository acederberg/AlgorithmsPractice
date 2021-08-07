# [Breadth First Search](https://en.wikipedia.org/wiki/Breadth-first_search)

Provided a tree, search all nodes at a particular depth before proceeding. This is particularly useful for inifinite trees as 'depth first search' reaches no end. Unfortunately it has horible time complexity bounds, the bound is in general the branching factor (the upper bound for the number of branches that any node may form) to the power of the depth, for finite trees, an upper bound for time complexity is the the sum of the number of nodes and the number of edges, e.g.

	Tree Time Complexity of <G, ~> = O( |G| + |G\~| / 2)

of course once again it is important to recall that `G` is a set and `~` is a relation (not an equivalence relation) on G and here 

	G\~ = { (x,y) in G X G such that x ~ y }

I use the backslash to be clear that these are not equivalence classes, but instead equivalence pairs.

# [Prompt](https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem)

Consider an undirected graph `<G, ~>` of order `n` where each vertex `g` in `G` is uniquely colored by its index (say index : G -> Integers is a bijection) with a constant edge for all nodes, e.g. `F: G X G -> Ints, x, y |-> K` for some integer `K`. Provided two nodes `x` and `y` in `G`, the distance between `x` and `y` will be the number of edges traversed to get from `x` to `y`, when the graph is disconnected and `x` and `y` lie in difference componants, then the distance will be `-1`. Find an algorithm to determine the mapping `F: vertex => dist( start, vertex )` for some `start` in `G`.

## Mathematical Answer

Let `s` in `G` be a starting point. Assume G is connected. We can start to define `F` by looking at the points imediately near it. These points will have distance `K` from `s`. Let the set of points considered be called `X(n)` for a depth `n`. If we look at the children of `X \ s` then the distance for these from the start will be `2K`, and we may extend `F` since `s` and `X \ s` are disjoint. This may be done continually until we have enumerated the points, e.g.

	F restricted to X(n) = {
		index(item) : kK
		for item in X(k) \ X(k - 1)
		for k in 1, ..., n
	}

so we may construct a mapping for each componant and create a mapping by using the definitions on each componant of the graph since componants are disjoint. Note that we don't have to worry about override the domain since there each vertex in `G` maps to a single value since `index` is a bijection.

## Proceedure

	F = {}

	# Look at each componant so that we may define F by looking at the mapping on each componant.
	foreach componant H of G:
		
		# When in connected do a BFS. X_H(k) represents the BFS.
		if start in H:

			n = depth(H)
			for each X_H(k) where k in 1, ..., n:
					
				# Image is constant on each X_H(k)
				F_H( X_H(k) ) =  kK 
		
		# When not in connected, map each point in the compant to -1.
		else: F_H( H ) = -1

	

## Example

Let 

	[1] --> [2] --> [5] --> [7]
		 |
		[3] --> [4]

	[6] --> [8]

be `<G, ~>`, and denote the top compant as `A` and the bottom as `B`. The number on each vertex is its image under `index` and the edges have constant color thus the color is not provided. Define the start point as [1].

Lets first consider `B`. Since `B` does not contain `[1]` its points will be mapped to `-1`, that is, `F([6]) = F([8]) = -1`.

Lets now consider the non-trivial componant `B`. We notice

	X_0 		= { [1] |}
	X_1 \ X_0	= { [2], [3] }
	X_2 \ X_1	= { [4], [5] }
	X_3 \ X_2	= { [7] }

thus F may be summarized as follows:

	[6], [8]	=> 		-1
	[1] 		=>		0
	[2], [3]	=> 		K
	[4], [5] 	=>		2K
	[7]		=> 		3K

where `K` is the color of all of the edges. To get this in the form desired by the prompt, that is, as a list where the index `k` corresponds to `J^(-1)(k + 2)` for `k in  0, ..., n - 1`, we would write this as 

	[K, K, 2K, 2K, -1, 3K, -1 ]

## Example Using the Adjacency Matrix

Let `G` be the graph
          _______________
         /               \  
	[0] --- [1] --- [2]
	 |    /  |    /
	 |   /   |   / 
	 |  /    |  / 
	[3] --- [4]

This has the adjacency matrix

	A + transpose(A)

where 

		0 K K K 0
	   	0 0 K K K
	A =	0 0 0 K K 
		0 0 0 0 K
		0 0 0 0 0

Let `A_j` be such a piece of the adjacency matrix of the `j`th step in Dijkstra's algorithm after reweighting the edges. We can get through the steps by using a sequence of graphs, in particular by removing the used nodes. This is the same as multiplying the adjacency matrix. Observe that after removing 1 and adding weight K to eac of the childrens edges we have

	[1] ---2K--- [2]
	 |  \         |
	 |   \        | 
	 |    \       |
	 2K    2K     2K 
	 |       \    |
         |        \   |
         |  	   \  |
 	[3] ---2K--- [4]


so 
		0  K  K  K  0
		0  0  2K 2K 2K
	A_1 =   0  0  0  2K 2K
		0  0  0  0  2K
		0  0  0  0  0

where the minor excluding the 0th row and column is the partial adjacency matrix of the above graph.  


Taking yet another step we have

	[3] ---4K--- [4] ---4K--- [5]

Thus

		0  K  K  K  0
		0  0  2K 2K 2K
	A_2 =   0  0  0  4K 4K  	
		0  0  0  0  4K
		0  0  0  0  0

and finally

		0  K  K  K  0
		0  0  2K 2K 2K
	A_3 =   0  0  0  4K 4K
		0  0  0  0  8K
		0  0  0  0  0

taking the non-zero minimum of the `k`th column we have the minimized distance to the kth node. Now the real question is how to do this using matrix multiplication. Suppose there exists a matrix `E_1` such that `A_1 = E_1 A`. Then we can find this matrix provided that the matrix. Really we just add values in the row of the best fit node to the subsequent rows non-zero values.


