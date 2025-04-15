//
// Created by halel on 4/9/25.
//

#include "Algorithms.h"
#include "Queue.h"
#include "Graph.h"
#include "myunionfind.h"
#include  "Node_V.h"
#include "PriorityQueue.h"


namespace graph {
    Graph Algorithms::bfs(Graph *original, Node_V *node) {
        nodimproved *info = new nodimproved[original->size];
        for (int i = 0; i < original->size; ++i) {
            info[i].color = 0;
            info[i].d = -1;
            info[i].father = Node_V(-1);
        }
        int startId = node->getData();
        info[startId].color = 1;
        info[startId].d = 0;
        info[startId].father = Node_V(startId);
        Queue q;
        q.enqueue(original->ArrayNode[startId]);
        Graph tree(original->size);
        while (!q.isEmpty()) {
            Node_V *u = q.dequeue();
            int u_id = u->getData();

            Edge *neighbors = original->ArrayEdge[u_id];
            while (neighbors != nullptr) {
                int v_id = neighbors->neighbor;
                if (info[v_id].color == 0) {
                    info[v_id].color = 1;
                    info[v_id].d = info[u_id].d + 1;
                    info[v_id].father = *u;

                    tree.addEdge(u_id, v_id);
                    q.enqueue(original->ArrayNode[v_id]);
                }
                neighbors = neighbors->next;
            }

            info[u_id].color = 2;
        }
        return tree;
    }
        Graph Algorithms::dfs(Graph *original, Node_V *start) {
            nodimproved *info = new nodimproved[original->size];
            for (int i = 0; i < original->size; ++i) {
                info[i].color = 0;
                info[i].father = Node_V();
            }

            Graph tree(original->size);

            int startId = start->getData();
            dfsVisit(original, startId, info, tree);

            delete[] info;
            return tree;
        }
    void Algorithms::dfsVisit(Graph* original, int u_id, nodimproved* info, Graph& tree) {
        info[u_id].color = 1;

        Edge* neighbor = original->ArrayEdge[u_id];
        while (neighbor != nullptr) {
            int v_id = neighbor->neighbor;
            if (info[v_id].color == 0) {
                info[v_id].father = Node_V(u_id);
                tree.addEdge(u_id, v_id);
                dfsVisit(original, v_id, info, tree);
            }
            neighbor = neighbor->next;
        }

        info[u_id].color = 2;
    }
    Graph Algorithms::dijkstra(Graph* original, Node_V* start) {

        nodimproved* info = new nodimproved[original->size];

        for (int i = 0; i < original->size; ++i) {
            info[i].color = 0;
            info[i].d = 1e9;
            info[i].father = Node_V();
        }

        int startId = start->getData();
        info[startId].d = 0;

        PriorityQueue pq;
        pq.insert(original->ArrayNode[startId], 0, original->ArrayNode[startId]);

        Graph shortestPathsTree(original->size);

        while (!pq.isEmpty()) {
            Node_V* u = pq.extractMin();
            int u_id = u->getData();

            if (info[u_id].color == 2) continue;

            info[u_id].color = 2;

            Edge* neighbor = original->ArrayEdge[u_id];
            while (neighbor != nullptr) {
                int v_id = neighbor->neighbor;
                int weight = neighbor->weight;

                if (info[u_id].d + weight < info[v_id].d) {
                    info[v_id].d = info[u_id].d + weight;
                    info[v_id].father = Node_V(u_id);
                    pq.insert(original->ArrayNode[v_id], info[v_id].d, original->ArrayNode[u_id]);
                    shortestPathsTree.addEdge(u_id, v_id, weight);
                }

                neighbor = neighbor->next;
            }
        }

        return shortestPathsTree;
    }


    Graph Algorithms::prim(Graph* original) {
        int n = original->size;
        nodimproved* info = new nodimproved[n];

        for (int i = 0; i < n; ++i) {
            info[i].color = 0;
            info[i].d = 1e9;
            info[i].father = Node_V();
        }

        int startId = 0;
        info[startId].d = 0;

        PriorityQueue pq;
        pq.insert(original->ArrayNode[startId], 0, original->ArrayNode[startId]);

        Graph mst(n);

        while (!pq.isEmpty()) {
            Node_V* u = pq.extractMin();
            int u_id = u->getData();

            if (info[u_id].color == 2) continue;

            info[u_id].color = 2;

            if (info[u_id].father.getData() != u_id) {
                int parent = info[u_id].father.getData();
                int weight = info[u_id].d;
                mst.addEdge(parent, u_id, weight);
            }

            Edge* neighbor = original->ArrayEdge[u_id];
            while (neighbor != nullptr) {
                int v_id = neighbor->neighbor;
                int w = neighbor->weight;

                if (info[v_id].color != 2 && w < info[v_id].d) {
                    info[v_id].d = w;
                    info[v_id].father = Node_V(u_id);
                    pq.insert(original->ArrayNode[v_id], w, original->ArrayNode[u_id]);
                }

                neighbor = neighbor->next;
            }
        }

        return mst;
    }
    Graph Algorithms::kruskal(Graph* original) {
        Graph mst(original->size);
        myunionfind uf(original->size);
        struct EdgeInfo {
            int u;
            int v;
            int weight;
        };

        int edgeCount = 0;
        EdgeInfo* edges = new EdgeInfo[original->size * original->size];

        for (int u = 0; u < original->size; ++u) {
            Edge* e = original->ArrayEdge[u];
            while (e != nullptr) {
                int v = e->neighbor;
                int w = e->weight;
                if (u < v) {
                    edges[edgeCount++] = {u, v, w};
                }
                e = e->next;
            }
        }

        for (int i = 0; i < edgeCount - 1; ++i) {
            for (int j = 0; j < edgeCount - i - 1; ++j) {
                if (edges[j].weight > edges[j + 1].weight) {
                    EdgeInfo temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < edgeCount; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;
            if (!uf.connected(u, v)) {
                uf.unite(u, v);
                mst.addEdge(u, v, edges[i].weight);
            }
        }

        delete[] edges;
        return mst;
    }




} // graph
