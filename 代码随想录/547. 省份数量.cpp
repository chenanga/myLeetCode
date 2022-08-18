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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) uf.UnionElements(i, j);
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
            if (uf.find(i) == i) ++res;
        return res;
    }
};