# Purpose

These are just some practice I'm doing to improve my algorithms and data structures knowledge. Implementations in various languages, though I will favor C/C++ and Python. Might try some assembly because it sounds fun.

# Complete and Sufficiently Complete

I am currently studying for a test and inted to return to each of these and improve them. In general they all work as expected, but there might be a few lose ends here or there.

## Arrays

A basic array. Written in `C`. Uses a struct containing a pointer to an array and the length since for integer arrays it is nice to atleast have length. Included simple methods for inserting, removing, showing, sorting, and setting array values.

## Stacks

A stack implemented in `C`. Uses a struct containing a pointer to memory used, height, and capacity. Includes simple methods, e.g. pop and push, as well as derived methods (not relying on the underlying array, but the stack itself) in particular there will be a sorting algorithm which uses the `disk game` method of sorting. For now this will not exists since I have to get through this content.

## Trees

A binary tree as implemented in `C`. Some algorithms including bredth flatttening, depth flattening, getting layers, etc. Also implements a queue for us to load nodes into.

## Queues

A character queue implemented in `C`. For now it only has the struct for the nodes in the queue (this is queue usess singly linked nodes), a struct for the queue itself, and finally fundimental methods for either.

## Nodes

Some reusable nodes implemented in `C` that I will start to use at some point.

## HackerRankProblems

Here I solve some HackerRank problems mostly in `Python` (because it is easy and fast to do it this way as opposed to `C`) mostly pertaining to graphs and trees.

# Comming soon...

## Linked Lists

This is easy and is implemented in the queue class. However I would still like to do this since it should be quick.

## Graphs

Some `Python` classes defining various types of graphs using a base class which is really just a wrapper for adjacency matrix. That is, graphs phrased in terms of the adjacency matrix. While classes exist and work, this is not my priority right now. However, I will still go back and finish the `Dijkstra` methods after I have done so with C.
