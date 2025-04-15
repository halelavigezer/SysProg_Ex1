#include <iostream>
#include "Graph.h"
#include "Algorithms.h"
#include "Queue.h"
#include "PriorityQueue.h"

int main() {
    using namespace graph;

    try {
        Graph g(5);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 4);

        std::cout << "Graph after adding edges:" << std::endl;
        g.print_graph();

        g.removeEdge(0, 1);
        std::cout << "\nGraph after removing edge between 0 and 1:" << std::endl;
        g.print_graph();

        Node_V* startNode = g.getNode(0);
        Algorithms algo;
        std::cout << "\nRunning BFS from starting node:" << std::endl;
        algo.bfs(&g, startNode);

        std::cout << "\nRunning DFS from starting node:" << std::endl;
        algo.dfs(&g, startNode);

        std::cout << "\nRunning Dijkstra algorithm:" << std::endl;
        algo.dijkstra(&g, startNode);

        std::cout << "\nRunning Prim's algorithm:" << std::endl;
        algo.prim(&g);

        std::cout << "\nRunning Kruskal's algorithm:" << std::endl;
        algo.kruskal(&g);

    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}
