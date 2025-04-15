#include "Algorithms.h"
#include "Graph.h"
#include "Node_V.h"
#include <iostream>

using namespace graph;

void test_bfs() {
    std::cout << "=== Testing BFS ===" << std::endl;
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    Algorithms algo;
    Graph tree = algo.bfs(&g, g.ArrayNode[0]);

    for (int i = 0; i < tree.size; ++i) {
        Edge* e = tree.ArrayEdge[i];
        while (e != nullptr) {
            std::cout << i << " -> " << e->neighbor << std::endl;
            e = e->next;
        }
    }
    std::cout << std::endl;
}

void test_dfs() {
    std::cout << "=== Testing DFS ===" << std::endl;
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    Algorithms algo;
    Graph tree = algo.dfs(&g, g.ArrayNode[0]);

    for (int i = 0; i < tree.size; ++i) {
        Edge* e = tree.ArrayEdge[i];
        while (e != nullptr) {
            std::cout << i << " -> " << e->neighbor << std::endl;
            e = e->next;
        }
    }
    std::cout << std::endl;
}

void test_dijkstra() {
    std::cout << "=== Testing Dijkstra ===" << std::endl;
    Graph g(5);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 3, 10);
    g.addEdge(2, 4, 3);
    g.addEdge(4, 3, 4);

    Algorithms algo;
    Graph tree = algo.dijkstra(&g, g.ArrayNode[0]);

    for (int i = 0; i < tree.size; ++i) {
        Edge* e = tree.ArrayEdge[i];
        while (e != nullptr) {
            std::cout << i << " -(" << e->weight << ")-> " << e->neighbor << std::endl;
            e = e->next;
        }
    }
    std::cout << std::endl;
}

void test_prim() {
    std::cout << "=== Testing Prim ===" << std::endl;
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    Algorithms algo;
    Graph mst = algo.prim(&g);

    for (int i = 0; i < mst.size; ++i) {
        Edge* e = mst.ArrayEdge[i];
        while (e != nullptr) {
            std::cout << i << " -(" << e->weight << ")-> " << e->neighbor << std::endl;
            e = e->next;
        }
    }
    std::cout << std::endl;
}

void test_kruskal() {
    std::cout << "=== Testing Kruskal ===" << std::endl;
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    Algorithms algo;
    Graph mst = algo.kruskal(&g);

    for (int i = 0; i < mst.size; ++i) {
        Edge* e = mst.ArrayEdge[i];
        while (e != nullptr) {
            std::cout << i << " -(" << e->weight << ")-> " << e->neighbor << std::endl;
            e = e->next;
        }
    }
    std::cout << std::endl;
}


