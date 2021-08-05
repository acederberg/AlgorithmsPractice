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
        super.__init__()
        self.colors = []
    
    def __str__(self):
        return "\n".join( item for item in (
                super.__str__(),
                "\t".join(self.colors)
            )+"\n"
        )

    def addVertex(self, neighbors, color):
        self.colors.append(color)
        super.addVertex(neighbors)

    def removeVertex(self, index):
        super.removeVertex(index)
        self.colors.pop[index]

class Tree(Graph):

    def __init__(self): self.addVertex({})
    def addVertex(self, base, *edges):
        "add nodes with edge colors `*edges` to adjacency matrix"
        if base >= self.size or base < 0: return
        super.addVertex( { base : edge for edge in edges } )

class ColoredTree(ColoredGraph):

    def __init__(self): 
        "The base of the tree will always be the vertex with index zero"
        super.__init__()
        self.addVertex({})
    
    def addVertex(self, base, vertex_color, node_color):
        "base is the index of the node to add to. Adds to adjacency matrix and colors"
        if base >= self.size or base < 0: return
        super.addVertex( {base : node_color}, color )
        

# Use the `Type` function from `typing` to indicate that this ought to take in all `Graph` objects and their children.
#def dijkstra(graph : Type(Graph) ):

class Dijkstra(Graph):
    "Graph with colored edges and methods to solve it using Dijkstra's method. This makes a graph which we can update in real time and for which we may keep a solution on hand"

    def crush(self, current, best):
        "Algorithm column reduction step. Add value of index best in column current to all non-zero in column current then nullify self."

        G = self.adjacency_matrix
        n = len(G[current])
        G[current] = [ 
            G[current][k] + G[current][best]  
            if G[current][k]
            else 0
            for k in range( 0, n )
        ]

        #G[current][best] = 0
        self.removeVertex(best)


    def next(self):
        "Get the best fit from active. Might just be max of the row of current index"
        return min( self.adjacency_matrix[ self.current ] )
        
#    def solve(self, start_index):
#        
#        H = Tree()
#        G = self.copy()
#        current = start_index
#        # A means to keep track of which graph nodes correspond to which tree nodes (domain and range respectively keys and values).
#        treemap = {}
#
#        while G: 
#            
#            # Find the best match
#            best = G.next()
#
#            # Add the vertex to output, record graph correspondance. Should be last value added.
#            H.addVertex()
#            treemap[current] = H.size - 1
#
#            # Reduce the adjacency matrix.
#            G.crush(
#                    current, 
#                    best,
#            )
#            current = best

if __name__ == "__main__":
    
    def makeDummy():
        G = Dijkstra() 
        G.addVertex( {} )
        G.addVertex( {0 : 10} )
        G.addVertex( {} )
        G.addVertex( {0 : 3, 1 : 4, 2 : 1} ) 
        G.addVertex( {1 : 2, 2 : 12} )
        return G

    G = makeDummy()
    print(G)
    print("\nReducing...\n")
    G.crush(3, 0)
    print(G)

    
