# Provided some stack of non-repeating numbers, sort it using two other initially empty stacks.
# These two other stacks must remain in descending order.
# In the game, the total number of spaces occupied must fit the number in the initial stack.

def top( A : list ): return A[ len(A) - 1] if A else 0
def move( move_from, move_to): move_to.append( move_from.pop() )

def _sort( active, last_from, last_to ):

    print( f"---------------------------\n{active = }\n{last_from = }\n{last_to = }." )
    # Because we don't consider the column we just moved something onto, `last_to`, since it is by definition full.
    mt = 0 if not active else ( 1 if not last_from else None)
    cols = ( active, last_from, last_to )
    # find the least difference between column tops.
    tops = tuple( top(item) for item in cols )
    # There will be at most one empty
    if mt is not None:

        # pointers for convenience. Move largest value not last moved to mt, col with such value is `move_from`
        move_to = cols[mt]
        tallest = tops.index( max( tops ) ) 
        print(f"{tallest = }")
        move_from = cols[ tallest ]
        move(move_from, move_to)
        
        static = tuple( item for item in range(0, 3) if item != mt and item != tallest )[0]
        print(static)
        static = cols(static)

        # Recurse This way
        _sort( 
                last_to, #because nothing happened on this turn,
                move_from, #beacause we can move something here,
                move_to #but we musn't move this.
        )

    else:
       
        a, f, t = tops
        data = ( a - f, f - t, t - a)
        print(f"{data = }") 

        # find the minimized positive. should move first in data dif to second
        best = data.index( min( item for item in data if item > 0 ) )
        print(f"{best = }") 
#         if best == 0: move_to, move_from, static = active, last_from, last_to
#         elif best == 1: move_to, move_from, static = last_from, last_to, active
#         else: move_to, move_from, static = last_to, active, last_from
        
        move_to, move_from, static = ( cols[ (k  + best) % 3 ] for k in range(0, 3) )
        
        move( move_from, move_to ) 

        _sort(
                static,
                move_from,
                move_to
        )

        
def sort(A : list):

    n = len(A) 

    # last_from is the initial stack minus its top two since it will be the last columns filled after these two turns.
    last_from = A.copy()
    active =    [ last_from.pop() ]
    last_to =   [ last_from.pop() ]

    _sort( active, last_to, last_from )


if __name__ == "__main__":

    # Simulate stacks using lists. Only append or remove from the end.
    A = [2, 3, 1, 4, 5]
    sort(A)
