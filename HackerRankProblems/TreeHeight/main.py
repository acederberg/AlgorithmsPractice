class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def show(self, start = None, depth = 0):

        if not start: start = self.root
    
        tabs = depth * "\t"
        depth += 2
        
        print(f"{tabs}BRANCHSTART")
        print(f"{tabs}value = {start.info}")

        if start.left:
            print(f"{tabs}Left")
            self.show(start.left, depth)

        if start.right:
            print(f"{tabs}Right")
            self.show(start.right, depth)

        print(f"{tabs}ENDBRANCH")

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

# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
class Node:
      def __init__(self,info): 
          self.info = info  
          self.left = None  
          self.right = None 
           

       // this is a node of the tree , which contains info as data, left , right
'''

def _height(lastLayer : list, current : int, objective : int):
    "Recurser for the height method. takes a list of nodes, checks nodes in list for children, return a list of those children or searchs that layer for children until at depth `objective`."
    print(lastLayer)    
    out = []
    for node in lastLayer:

        if node.left: out.append( node.left ) 
        if node.right: out.append( node.right )
    
    # clear crap memory
    del lastLayer
    current += 1

    # if current is deep enough return else recurse
    return out if current == objective else _height(out, current, objective)

def height(root):
    

    layer = [ root ]
    k = 0
    # bc no do while
    layer = _height(layer, k, k + 1)
    
    while layer:

        layer = _height(layer, k, k + 1)
        k += 1

    return k
    
        




def get():

    tree = BinarySearchTree()
    t = int(input("Enter the number of nodes in your tree.\n\n\t"))
    print()

    arr = list(map(int, input("Enter the numers from 1 to {t} in some order.\n\n\t").split()))
    print()

    for i in range(t): tree.create(arr[i])

    tree.show()
    print(height(tree.root))


if __name__ == "__main__": get()
