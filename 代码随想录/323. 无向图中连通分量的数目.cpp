#include "general.h"
class UnionFind {
public:
    UnionFind(int n) {
        parent = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool isConnect(int p, int q) { return find(p) == find(q); }

    void UnionElements(int p, int q) { parent[find(p)] = find(q); }

private:
    vector<int> parent;
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (int i = 0; i < edges.size(); ++i) {
            uf.UnionElements(edges[i][0], edges[i][1]);
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            if (uf.find(i) == i) ++res;
        return res;
    }
};