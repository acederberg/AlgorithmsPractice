"""
DESCRIPTION: Provided a Graph with vertextes colored uniquely by integers with constant coloring along the edges as represented by the ordered pairs (as a list of lists), generate a list where the `k`th index is filled by the distance to the `k`th vertex (as determined by the sum of the edge colors) from some provided starting vertex indicated (uniquely) by its color.

INPUT FORMAT: The `getInput` method will get the following each line in the following order

    1. An integer representing how many graphs to be input.
    2. More integers representing the number of nodes and edges respectively.
    3. Two whitespaced integers describing an edge from `u` to `v`. This goes for as many lines as provided for the number of edges.
    4. The starting node.
"""

class Graph:

    def __init__(self, n : int):
        self.length = n
        self.init_size = n
        self.edges = []

    def __bool__(self): return bool(self.edges)

    def connect(self, x : int, y : int) -> None: self.edges.append([x, y])

    def get_edges(self, value : int) -> iter: 
        k = 0
        while k <  self.length:
            #print(f"{value = }, {k = }, {self.length = }, { self.edges = }")
            if value in self.edges[k]: 
                out = self.edges[k]
                self.edges.pop(k)
                self.length -= 1
                yield out
            else: k += 1

    def update(self, out, used, start):
           
        if not self or start > self.init_size: return

        edges = self.get_edges( start )
        used.append(start)

        # look at the edges on a particular node
        for edge in edges:
        
            notstart =  1 if edge[1] != start else 0
            
            # fill in if zero or better value.
            if out[ edge[ notstart ] ] == 0 or out[ edge[ notstart ] ] >=  out[ edge[not notstart] ] + 6:
                
                print("HERE")
                out[ edge[ notstart ] ] = out[ edge[not notstart] ] + 6
                print(f"{ edge = }\t{ out = }\t{ used = }")
           
        # move to the best one like dijkstras    
        # get unused with minimal distance to true start
        minimal = min(out)
        k = 0
        while out.index(minimal, k) in used: k += 1
        print(start)
        self.update(out, used, k)

        


    def find_all_distances(self, start : int):

        # save size since will be modifying in get_edges
        size = self.length

        temp = start
        out = self.length * [0]
        used = []

        self.update(out, used, start)
    
        return out

def makeDummy():

    G = Graph(5)

    G.connect(0,1)
    G.connect(0,2)
    G.connect(1,2)
    G.connect(3,2)
    G.connect(4,2)
    G.connect(3,0)
    
    return G

if __name__ == "__main__":

    G = makeDummy()
    A = G.find_all_distances(0)



def getInput():
    "Constructs graph from user input as described in the file docstring."

    # Get number of queeries
    t = int(input())

    for i in range(t):
    
        
        # Create graph instance from input
        n_vertices, n_edges = [int(value) for value in input().split()]
        graph = Graph( n_vertices )

        # get n_edges edges
        for i in range( n_edges):
            
            x,y = [
                    int(x) 
                    for x in input().split()
            ]
            graph.connect( x - 1, y - 1)

        # input the number of the starting point.
        start = int( input() )

        # Get output
        graph.find_all_distances(start - 1)
