
# move all smaller than partition to before and all larger to after
def _partition( arr, pi ):
    end = len( arr ) - 1
    # Move pivot to the end 
    arr[ end ], arr[ pi ] = arr[ pi ], arr[ end ] 

    # start from top and bottom, move until 
    left = 0; right = len( arr ) - 2
    while True:
        
        # find large to left
        while arr[left] < arr[ end ]: left += 1
        # find small to the right
        while arr[right] > arr[ end ]: right -= 1
        # switch when left is less than right. Else stop
        if left < right: arr[ left ], arr[ right ] =  arr[ right ], arr[ left ]
        else: break
        print( arr )

    # Move the pivot back to its appropriate position
    print( left, right )
    arr[ end ], arr[ left ] = arr[ left ], arr[ end ]

def _sort(arr, start, end):
    pass
    

if __name__ == "__main__":

    A = [2,1,3,8,5,1,35,13,21]
    _partition( A, len(A) // 2 )
    print( A)
