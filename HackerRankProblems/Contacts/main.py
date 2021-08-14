from tree import Dummy, Tree

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'contacts' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts 2D_STRING_ARRAY queries as parameter.
#

def add(T, name): T.add(name)

def first(T, name): 
    # In BST, when we get less than the start for all left.
    # Traverse leftward until find first starting with
    current = T.root
    while current:
        if current.value.startswith( name ):    break
        if current.value < name:                current = current.left
        else:                                   current = current.right
    # Returns none if nothing turns up.
    return current

def find(T, name):
    """ Bredth first search for after the first node is found."""
    data = first(T, name) 
    if not data: return 0

    last, current = [ data ], []
    count = 0
    while last:
        # count the good nodes on this level. 
        for c in last:
            if c.value.startswith(name): count+=1    
        
            # If node is good, save to check children.
            if c.left: current.append(c.left)
            if c.right: current.append(c.right)

        last = current
        current = []

    return count

def contacts(queries):
    # Write your code here
    T = Tree(None)
    out = []
    for q in queries:
        q, data = q
        if q == "find": out.append( find(T, data) )
        else: add(T, data)
    return out

def getInput():
    queries_rows = int(input().strip())
    queries = []
    
    for _ in range(queries_rows):
        queries.append(input().rstrip().split())

    print(queries)
    result = contacts(queries)
    print(result)

if __name__ == '__main__':

    #T = Dummy()
    #print(    find(T, "ba"))
    #if input() != "": T.show()

    with open("input06.txt", "r") as file:
        contacts( [ line.split() for line in file.readlines()[0:] if line.count(" ") == 1] )

