
def _sort( arr ):
    n = len(arr)
    if n <= 1: return arr

    center = [arr.pop() for k in range(0, n // 2)]
    
    center = _sort( center ) 
    arr = _sort( arr )
    
    out = [ None for item in range( 0, len(center) + len(arr) ) ]

    i = j = k = 0
    n, m = len(arr), len(center)

    while i < n and j < m :
        print(f"{arr = }, {center =}")
        if arr[ i ] < center[ j ]:
            out[k] = arr[i]
            i += 1
        else:
            out[k] = center[j]
            j += 1

        k += 1
    
    while i < n: 
        out[ k ] = arr[ i ]
        k += 1
        i += 1
    while j < m:
        out[ k ] = center[ j ]
        k += 1
        j += 1

    return out

if __name__ == "__main__":

    A = [2,1,3,4,7,11,18,29,47,76]
    B = _sort( A )
    print(B)
