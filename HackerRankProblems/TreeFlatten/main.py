class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(f"{ self.info = }\t{ self.right = }\t{self.left}") 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.info (the value of the node)
"""

def _levelOrder(flattened : list, start : int, stop : int):
    "start and stop are the indexing determing where the previous layers contents lie, start is the first of the previous row and stop is the index of this row."
    
    # Adder
    for k in range( start, stop ):
        
        item = flattened[k]

        if item.left:   
            print( f"{item.info} has left child { item.left.info }" )
            flattened.append( item.left  )
        if item.right:  
            print( f"{item.info} as right child { item.right.info }" )
            flattened.append( item.right )

    # Recurser
    if stop == len( flattened ): return 
    else: _levelOrder( flattened, stop, len( flattened ) )
    
    
def levelOrder(root):
    # Create flattened. Call the _flattened method. It will stop when it finds an empty layer.
    flattened = [root]
    _levelOrder( flattened, 0, 1 )
    # print
    for item in flattened: print( item.info , sep = " ")
    # return flattened

def getInput():
    tree = BinarySearchTree()
    t = int(input())

    arr = list(map(int, input().split()))

    for i in range(t):
        tree.create(arr[i])

    levelOrder(tree.root)
    

if __name__ == "__main__": getInput()
