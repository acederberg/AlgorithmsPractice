from typing import Type
from abc import ABC

class Graph(ABC):
    """ Nodes are not to have own value, only value is index. In the children we will deal with this individually. This is just for the `abstraction`. """
    def __bool__(self): return bool( self.adjacency_matrix )

    def __init__(self, adjacency_matrix = None):
        # Not an actual matrix, only need one half since undirected graphs have symetric adjacency matrices
        self.adjacency_matrix = [] if not adjacency_matrix else adjacency_matrix
        self.size = 0

    def __iter__(self): 
        """ Iterate through the rows of self as iterators of columns. Used in the `__str__` and `matrix` methods."""
        return (
            (
                self.adjacency_matrix[k][j] if switched else self.adjacency_matrix[j][k]
                for switched in (1, 0)
                for j in range(  
                    0 if switched else len( self.adjacency_matrix[k] ),    
                    len( self.adjacency_matrix[k] ) if switched else self.size
                )   
            )
            for k in range(0, self.size)
        )

    def __str__(self): return  "\n".join(
            "\t".join(
                str( thing ) 
                for thing in item
            )
            for item in self.__iter__()
    ) 

    def addVertex(self, neighbors):
        """`neighbors` should specify the index of the neighboring vertex by index and the value of the edge by value. E.g. passing in {4 : 3} will add a new node with an edge to node 4 of weight three """
        self.size += 1
        self.adjacency_matrix.append( 
                [
                    0
                    if k not in neighbors
                    else
                        neighbors[k]
                    for k in range(0, self.size)
                ]
        )

    def copy(self): return Graph(self.adjacency_matrix)

    def get(self, row, col): 
        if col >= row: row, col = col, row
        return self.adjacency_matrix[row][col]
        

    # Will eliminate redundancies later
    def iterRow(self, row):
        # Use transpose
        for k in range( 0, row): yield self.adjacency_matrix[row][k]
        for k in range( row, self.size): yield self.adjacency_matrix[k][row]

    def iterCol(self, col):
        # Use transpose again
        for k in range(col, self.size): yield self.adjacency_matrix[k][col]
        for k in range(0, col): yield self.adjacency_matrix[col][k]

    def hasNeighbors(self, index):
        "A vertex has no neighbors when its repective row and column in the adjacency matrix have only a diagonal value"
        badcol = sum( 
                self.adjacency_matrix[k][index] 
                for k in range(index + 1, self.size) 
        )
        if badcol: return false
        badrow = sum( self.adjacency_matrix[index] )
        return not badrow

    def removeVertex(self, index):
        "To remove a vertex from the adjacency matrix, one removes the vertexes corresponding rows and columns. Since here only symettric graphs are considered we remove half the number in our representation"
        for k in range(index, self.size): self.adjacency_matrix[k].pop(index)
        self.adjacency_matrix.pop(index)
        self.size -= 1

    def matrix(self):
        return [
            list(item)
            for item in self.__iter__()
        ]

class ColoredGraph(Graph):
    "Adds coloring to the vertices, an extra layer above the adjacency matrix"
    def __init__(self): 
        "Adds the colors attribute as list. color at index corresponds to the node with the same index in the adjacency matrix"
        super().__init__()
        self.colors = []
    
    def __str__(self): return "\n" + super().__str__() + "\nVertex Colors:\n" + "\t".join( 
            str(item) 
            for item in self.colors
    ) + "\n"
        

    def addVertex(self, neighbors, color):
        self.colors.append(color)
        super().addVertex(neighbors)

    def removeVertex(self, index):
        super().removeVertex(index)
        self.colors.pop[index]

class Tree(Graph):

    def __init__(self): 
        super().__init__()
        self.addVertex({})

    def addVertex(self, base, *edges):
        "add nodes with edge colors `*edges` to adjacency matrix"
        if base >= self.size or base < 0: return
        super().addVertex( { base : edge for edge in edges } )

# If a class inherets from children of the same parent, is it insest?
class ColoredTree(ColoredGraph):

    def __init__(self, basecolor): 
        "The base of the tree will always be the vertex with index zero"
        super().__init__()
        super().addVertex( {}, basecolor )
        # self.colors.append(basecolor)
    
    def addVertex(self, base, vertex_color, node_color):
        "base is the index of the node to add to. Adds to adjacency matrix and colors"
        if base >= self.size or base < 0: return
        super().addVertex( {base : node_color}, vertex_color )


