    //
    // Created by halel on 4/9/25.
    //

    #ifndef ALGORITHMS_H
    #define ALGORITHMS_H
    #include "Graph.h"

    namespace graph {
        struct nodimproved {
            int color;
            int d;
            Node_V father;
        };

    class Algorithms {
    public:
        Graph bfs(Graph* original, Node_V* node);
        Graph dfs(Graph* original, Node_V* node);
        Graph dijkstra(Graph* original, Node_V* node);
        Graph prim(Graph* original);
        Graph kruskal(Graph* original);
        void dfsVisit(Graph* original, int u_id, nodimproved* info, Graph& tree);



    };

    } // graph

    #endif //ALGORITHMS_H
