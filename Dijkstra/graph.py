class graph:
    """ Nodes are not to have own value, only value is index """

    def __init__(self, adjacency_matrix = None):
        # Not an actual matrix, only need one half since undirected graphs have symetric adjacency matrices
        self.adjacency_matrix = [] if not adjacency_matrix else adjacency_matrix
        self.size = 0

    def __iter__(self): 
        """ Iterate through the rows of self as iterators. Used in the `__str__` and `matrix` methods."""
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

    def matrix(self):
        return [
            list(item)
            for item in self.__iter__()
        ]


class dijkstra( graph ):

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

        G[current][best] = 0

    def next(self):
        "Get the best fit from active. Might just be max of the row of current index"
        return min(self.adjacency_matrix[ self.current ]
        
    def solve(self, start_index):
        H = graph()
        H.addVertex(start_index)

        self.done = [start_index]


if __name__ == "__main__":
    
    def makeDummy():
        G = dijkstra()
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

    
