
System Programming Project 2 - Graph Algorithms
Overview
This project implements several graph algorithms including BFS, DFS, Dijkstra, Prim’s, and Kruskal’s. These algorithms are applied on a graph data structure which supports adding and removing edges. The algorithms work without using the C++ standard library (STL), and the project makes use of basic data structures such as queues, priority queues, and union-find.

Project Structure
Main Components:
Graph.h / Graph.cpp: Defines the Graph class, which represents a graph with nodes and edges. It includes methods for adding and removing edges, as well as printing the graph.

Algorithms.h / Algorithms.cpp: Contains the implementation of the graph algorithms: BFS, DFS, Dijkstra, Prim’s, and Kruskal’s.

Queue.h / Queue.cpp: Implements a queue data structure used in BFS.

PriorityQueue.h / PriorityQueue.cpp: Implements a priority queue used in Dijkstra and Prim’s algorithms.

myunionfind.h / myunionfind.cpp: Implements the union-find data structure used in Kruskal’s algorithm.

Node_V.h / Node_V.cpp: Defines the Node_V class, which represents nodes in the graph.

main.cpp: Contains the main function which demonstrates how to use the graph and algorithms.

Supporting Files:
Makefile: A file used to compile and build the project.

README.md: This file, which provides an overview of the project and its structure.

Algorithm Descriptions
1. Breadth-First Search (BFS)
BFS explores a graph level by level, starting from the given node. It marks each node with its distance from the source and tracks the parent node for each visited node.

2. Depth-First Search (DFS)
DFS explores a graph by traversing as deep as possible along each branch before backtracking. It marks nodes and tracks the parent for each node visited.

3. Dijkstra's Algorithm
Dijkstra's algorithm finds the shortest path from a starting node to all other nodes in a weighted graph. It uses a priority queue to process nodes with the smallest distance first.

4. Prim's Algorithm
Prim's algorithm is used to find the minimum spanning tree (MST) of a graph. It starts with an arbitrary node and grows the MST by adding the minimum weight edge that connects a new node to the MST.

5. Kruskal's Algorithm
Kruskal's algorithm also finds the minimum spanning tree of a graph. It sorts all edges by weight and adds edges to the MST if they connect two previously unconnected components, using the union-find data structure to keep track of connected components.

How to Use the Project
Compilation: To compile the project, run the following command in the terminal:

go
Copy
Edit
make
Execution: After compilation, run the program with:

bash
Copy
Edit
./runApp
Testing: The program demonstrates the usage of the algorithms in the main.cpp file. Each algorithm is applied to a graph, and the results are printed to the console.

Files and Functions
Graph Class
addEdge(int u, int v): Adds an edge between nodes u and v.

removeEdge(int u, int v): Removes the edge between nodes u and v.

print_graph(): Prints the graph to the console.

Algorithms Class
bfs(Graph original, Node_V start)**: Implements the Breadth-First Search algorithm.

dfs(Graph original, Node_V start)**: Implements the Depth-First Search algorithm.

dijkstra(Graph original, Node_V start)**: Implements Dijkstra's algorithm for shortest path.

*prim(Graph original)**: Implements Prim's algorithm for minimum spanning tree.

*kruskal(Graph original)**: Implements Kruskal's algorithm for minimum spanning tree.

Queue Class
*enqueue(Node_V node)**: Adds a node to the queue.

dequeue(): Removes and returns the front node from the queue.

isEmpty(): Checks if the queue is empty.

PriorityQueue Class
insert(Node_V node, int priority, Node_V parent)**: Inserts a node with a given priority.

extractMin(): Removes and returns the node with the minimum priority.

UnionFind Class (myunionfind)
connected(int u, int v): Checks if nodes u and v are connected.

unite(int u, int v): Unites the components containing u and v.

Node_V Class
getData(): Returns the data of the node.

setData(int data): Sets the data of the node.

Additional Notes
The algorithms have been implemented without using the standard C++ library data structures (such as std::queue or std::priority_queue).

The program is designed to be modular, with each component having a clear responsibility.

Error handling is included in the main.cpp file, with appropriate messages displayed if an exception is thrown.

Conclusion
This project demonstrates the implementation and use of fundamental graph algorithms. It provides an example of how to represent a graph and apply different algorithms to solve problems like finding shortest 


# SysProg_Ex1
I got help from these resources:
- https://chatgpt.com/share/67f4d180-de30-8011-af99-f3c3e5d9fa7f
- I used lesson summaries from Algorithms 1.
- And the summaries of the lessons and the presentations
  
