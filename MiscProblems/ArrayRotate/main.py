
def show(array):
    """ Show a 2d list like a matrix. """

    n = len(array)
    print( "\n".join(
        " ".join(
            f"{ array[k][j] }      "[0:3]
            for j in range(0, n)
        )
        for k in range(0,n)
    ), end = "\n\n" )

def transpose(array):
    """ Transpose 2d list like a matrix. """

    n = len(array)
    for row in range(0, n):
        for col in  range(row, n):
            array[col][row], array[row][col] = array[row][col], array[col][row]

def reflect(array):
    """ Reflect 2d list vertically about its center. """

    n = len(array)
    for row in range(0, n):
        for col in (0, n // 2):
            ref = n - 1 - col
            # print( f"{row = }, {col = }, {n - 1 - col = }")
            array[row][col], array[row][ref] = array[row][ref], array[row][col]

def mapping_demo():
    """ Shows how 90 degree rotation works using transposition and reflection. """
    
    A = [
        [1,  2,  3,  4  ],
        [5,  6,  7,  8  ],
        [9,  10, 11, 12 ],
        [13, 14, 15, 16 ]
    ]
    print("Initial Matrix:")
    show(A)
    print("Transposing matrix in place...", "Transposed Matrix:")
    transpose(A)
    show(A)
    print("Reflecting matrix in place...", "Final product (90 degree rotation)")
    reflect(A)

def _rotate(array):
    """ Helper method for `rotate`. Enuerates coordinates of cells to be moved. Every four make a complete cycle, e.g. rotating any of those cells will get it to another cell in the cycle. """
    n = len(array)
    col = None
    for row in range(0, n // 2 ):
        for col in range(row, n - row - 1 ):
            # print(f"{row = }, {col = }.")
            refrow = n - 1 - col
            refcol = n - 1 - row
            yield (row, col)
            yield (refrow, row)
            yield (refcol, refrow)
            yield (col, refcol)
        

def rotate(array):
    """ Take an array, rotate the layers 90 degrees to achieve total rotation by 90 degrees. """
    
    # Initialize count, get iterator.
    coords = _rotate(array)

    # Go until throws error
    while True:

        # save the value at first to assign at end since will be overriden.
        try:            last = next( coords )
        except Exception as E:
            print(f"Iteration stopped. {E}")
            break
        first = array[ last[0] ][ last[1] ]

        # shift the next three.
        for k in range(0, 3 ):
            
            # get next, shift, save current for next.
            current = next( coords )
            array[ last[0] ][ last[1] ] = array[current[0] ][ current[1] ]                         
            last = current 
        
        # Assign first from saved data as overriden.
        array[current[0] ][ current[1] ] = first
        show(array)

        yield

def sequence_demo():
    B = [
        [0,  1,  2,  3,  4,  5,  6],
        [7,  8,  9,  10, 11, 12, 13],
        [14, 15, 16, 17, 18, 19, 20],
        [21, 22, 23, 24, 25, 26, 27],
        [28, 29, 30, 31, 32, 33, 34],
        [35, 36, 37, 38, 39, 40, 41],
        [42, 43, 44, 45, 46, 47, 48]
    ]
    print("Initial matrix:")
    show(B)

    for step in rotate(B):
        input("Press enter to see the next step")
        show(B)
    

     
if __name__ == "__main__":
    while True: mapping_demo() if input("Enter T to see the the mapping demo or anything else to use the sequence demo...") == "T" else sequence_demo()
    
    
