# Array Rotations

## Maths

Roughly speaking, we have a matrix which we would like to rotate in place by 90 degrees. For instance

	[1, 0, 2]    [0, 0, 1]
	[0, 1, 0] => [0, 1, 0]
	[0, 0, 1]    [1, 0, 2]

is what we are trying to get to happen. One can write this as a reflection followed by a rotation. Observe:

	a b c d		transpose	a e i m		reflect		m i e a
	e f g h		-------->	b f j n		------->	n j f b
	i j k l				c g k o				o k g c
	m n o p				d h l p				p l h d

it will take `n^2 - n` operations to transpose (individual swaps) and n^2 operations to do reflection. Fortunately, these steps are cheap. However, we can do better if we realize that we can shift four cells simultaniously and reduce the looping, e.g.

	(row, col)	->	(col, refrow)
	     ^ 			       |
	     |			       |
	(refcol, row)	<-	(refrow, refcol)

where 

	refrow = n - 1 - row
	refcol = n - 1 - col

for three cells in each row whose rotations (the cells in the above diagram) are non-intersecting. Observe 

	1 2 3
	4 5 6 
	7 8 9

and notice that if we choose to use the cells of value 1 and 2 for rotation on the outermost layer we get

	7 2 1
	4 5 6
 	9 8 3

after the first step and

	7 4 1
	8 5 2
	9 6 3

after the second step.

In terms of mathematics, it is satifying to see that there is a solution through mapping (the first solution) and the sequence mapping (the second solution).

# Implementation

I implemented this in `Python`. I set it up so that one may use the mapping solution or the sequence solution.
