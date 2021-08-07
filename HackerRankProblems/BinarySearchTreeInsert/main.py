class Node:
    def __init__(self, info):
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

    def __repr__(self): 
        out = f"{self.info = }"
        if self.left: out += f"\t{self.left.info = }"
        if self.right: out += f"\t{self.right.info = }"
        return out

def preOrder(root):
    if root == None:
        return
    print (root.info, end=" ")
    preOrder(root.left)
    preOrder(root.right)

# ---------------------------------------------------------- #

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def show(self, node, depth = 0):

        if not node: return
        tabs = depth * "\t"
        print(tabs + "BRANCH")
        print( tabs + repr(node) )
        if node.left:
            print(tabs + "LEFT:")
            self.show(node.left, depth + 1)
        if node.right:
            print(tabs + "RIGHT:")
            self.show(node.right, depth + 1)
        
        print(tabs + "ENDBRANCH")
        
    def insert(self, val):
        
        if not self.root: self.root = Node( val )
        else:
            self._insert(self.root, val)

    def _insert(self, node, value):
             
            if node.info > value:
    
                if node.left is None: node.left = Node(value)
                else: self._insert(node.left, value)
            
            else:
        
                if node.right is None: node.right = Node(value)
                else: self._insert(node.right, value)
            



# ---------------------------------------------------------- #

def getInput():
    tree = BinarySearchTree()
    t = int(input("\nPlease enter the size of the array of items to be appended:\n\n\t"))
    print()

    arr = list(map(int, input(f"\nEnter {t} numbers separated by whitespace on the following line.\n\n\t").split()))
    print(f"\n{arr = }")

    for i in range(t): tree.insert(arr[i])
     
    tree.show(tree.root)

    preOrder(tree.root)
    
    return tree

if __name__ == "__main__": 
    A = getInput()
