# Binary Search

If you don't know, now you know: [Binary Search](https://www.geeksforgeeks.org/binary-search/)

The idea is roughly the same idea that has been aplied to real valued functions, but instead we take a linear data structure and represent it as a mapping from non-negative integers to the stored values (so called indexing). If this linear data structure is sorted, then we have a monotonic enough function that looking at any two values one may determine if there is a point with that particular value in the domain. Take for instance the mapping defined as follows:

	0 -> 1
	1 -> 1
	2 -> 2
	3 -> 3
	4 -> 5
	5 -> 8
	6 -> 13

If we are searching for the number 4 in the linear data structure which this represents, then one may look at the endpoints in the image (of the entire domain) and notice that 4 is between 1 and 13. One might ask at that point, how might we determine a smaller neighborhood in which to look -- The answer is nice, we may split the domain in half. How? Look for a subset of the domain in which the value may lie, here that domain is `D = {4, 5, 6}` with the image {5, 8, 13}. Since the complement to `D` has an image strictly less than 4, we can ignore it, but the other has an image strictly greater than four so we may stop. Of course, determining such things with code adds to our time complexity. The most basic form of the algorithm is as follows. A step is roughly the following:

	f : (v, a_1, ..., a_n) -> (a_1, ..., a_{m-1}) if v < a_m else (a_m, ..., a_n) where m = floor(n, 2)

except we must stop if the midpoint matches the value (this works since if we bisect sufficiently many times, we will end up with a list of length one or an empty list). In consise terms:

	def bs( data, v):

		if len( data ) <= 1: 
			n = len( data )
			return data[0] == v if n else False
		else:
			data = f(v, data )
			return bs ( data )	

In my solution I make sure to use memory more efficiently - instead of construct a new list on every recursion, we use the same list (since in python it works like a pointer) but remove the values we are no longer interested in. Of course, this could hinder time complexity, though as far as I know, the `list.pop` method is fairly efficient.

## Time complexity

The time complexity of the above algorithm is fairly straight forward. Assume that we have a list of length `N`. The greatest number of turns that we may have to take will be the case where the search ends on the last possible step (I say this because some implementations actually look v vs the endpoints every recursion). So we need to really just figure out how many times we must divide `N` by 2 to reach a length of one for our data, e.g.

	N / 2^steps = 1

which may be solve by eliminating the denominator and taking the base-2 logarithm:

	ln(n) = steps.

# Space complexity

I will talk about my implementation in this section. My implementation will destroy a copy of the list as we go, so we have only the one duplication and the local variables stored, which I will assume to be negligable. This means, when we pass in a list of size `N`, we can expect the function to take `O(N)` memory.




