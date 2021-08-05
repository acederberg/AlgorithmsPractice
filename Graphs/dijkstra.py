from graphs import Graph, ColoredTree

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

        # remove since we will not visit again
        self.removeVertex(best)

    def next(self, current):
        "Get next current. Looks at min in row and column. Since we search with them equal, just one suffices."
        values = list( self.iterRow(current) )
        print(current)
        return values.index( min( 
                item for item in values 
                if item != 0 
        ))
        
    def solve(self, start_index):
        "Make self into tree describing minimized paths. Coloring of output vertices are the indexes of the respective node in the graph as designated by their position in the adjacency matrix, coloring of the edges matches the coloring inbetween the respective edges in the graph."

        H = ColoredTree(start_index) 

        current = start_index

        # Problem: We need to update values
        while G:
            
            best = self.next( current )
            print(f"{current = }, {best = }, {self.adjacency_matrix[current] =}")
            H.addVertex(
                    0, 
                    start_index, 
                    self.get(best, current)
            )
            print("H = ", H)
            yield
            self.crush( current, best)

            current = best
            
        return H

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
    H = G.solve(0)
