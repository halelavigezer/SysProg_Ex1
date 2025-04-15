#include "myunionfind.h"

namespace graph {

    myunionfind::myunionfind(int n) {
        size = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    myunionfind::~myunionfind() {
        delete[] parent;
        delete[] rank;
    }

    int myunionfind::find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void myunionfind::unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;


        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool myunionfind::connected(int x, int y) {
        return find(x) == find(y);
    }

} // namespace graph
