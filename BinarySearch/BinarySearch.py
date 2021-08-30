def split( arr, first_half = True):
    "In place splitter"
    # If the first half is not needed, pop from zero m times.
    m = len( arr ) // 2
    arg = 0 if first_half else m
    for _ in range(0, m): arr.pop( arg )


def _binary_search( arr, value ):
    "Recurser"
    print( arr )
    # Assumes that the list is sorted.
    n = len( arr )
    mid = n // 2
    # print(n)
    # if we hit it at an endpoint, return true.
    if arr[ mid ] == value: return True
    # if we've run out of list, then stop.
    elif n <= 1: return value == arr if n == 1 else False
    # Get rid of the bad half by modifying in place.
    else:
        split( arr, arr[ mid ] < value )
        return _binary_search( arr, value )

def binary_search( arr, value ):
    # Make a copy since search is destructive.
    a = arr.copy()
    return _binary_search( a, value )

if __name__ == "__main__":

    A = [1,1,2,3,5,8,13,21,34,55,89,144]

    # Mapping from values to if they're in list or not.
    tests = {
        -12 : False,
        -6 : False,
        0 : False,
        4 : False,
        5 : True,
        6 : False,
        8 : True,
        20 : False,
        21 : True,
        55 : True,
        89 : True,
        145 : False
    }

    text = ("is not", "is")

    for test, solution in tests.items():
        print("--------------------------------------------")
        print(f"testing value {test}")

        r = binary_search(A, test)
        try: 
            assert r == solution
            print(f"{test} {text[solution]} in data.")
        except Exception as E:
            print(f"Failed for test value {test}. Got value {r} while it should be {solution}")

        input()
        


