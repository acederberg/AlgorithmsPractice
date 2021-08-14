class Node:
    def __init__(self, value : str):
        self.value = value
        self.left, self.right = None, None

class Tree:
    def __init__(self, root : str): self.root = Node(root) if root is not None else None
    def _add(self, value, node):
        
        # Good news: string less than or equals is alphabetization.
        # If less than value at node, see if children are mt. If not, recurse.
        if node.value > value:
            
            if node.right:  self._add(value, node.right)
            else:           node.right = Node(value)
        elif node.value == value: return
        else:

            if node.left:   self._add(value, node.left)
            else:           node.left = Node(value)

    def add(self, value):
        
        if not self.root: self.root = Node(value)
        else: self._add(value, self.root)

    def _show(self, what, ntabs = 0):
        
        tabs = ntabs*"\t"
        print(tabs + "BRANCH")
        print(f"{tabs}value = {what.value}")
        if what.left: 
            print(tabs + "RIGHT")
            self._show(what.left, ntabs + 1)
        if what.right:
            print(tabs + "LEFT")
            self._show(what.right, ntabs + 1)
        print(tabs + "ENDBRANCH")

    def show(self): self._show(self.root)

def Dummy():
    T = Tree("foo")
    T.add("bar")
    T.add("tomatoes")
    T.add("bangers")
    T.add("spam")
    T.add("eggs")
    T.add("marmite")
    T.add("beans")
    T.add("jam")
    T.add("bacon")
    T.add("hash")
    T.add("toast")
    return T

if __name__ == "__main__":
    
    T = Dummy()
    T.show()
