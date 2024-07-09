#include <bits/stdc++.h>
using namespace std;
class Set
{
    vector<int> parent, rank, size;

public:
    Set(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Initialize size of each set to 1

        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Each element is initially its own parent (self loop)
        }
    }

    // Find function with path compression
    int findpar(int node) {
        if (node == parent[node]) {
            return node; // If node is its own parent, return it
        }
        return parent[node] = findpar(parent[node]); // Path compression
    }

    // Union by Rank
    void UnionByRank(int u, int v) {
        int ultimate_parent_u = findpar(u);
        int ultimate_parent_v = findpar(v);

        if (ultimate_parent_u == ultimate_parent_v) {
            return; // They are already in the same set
        }

        if (rank[ultimate_parent_u] > rank[ultimate_parent_v]) {
            parent[ultimate_parent_v] = ultimate_parent_u; // Attach smaller tree under larger tree
        } else if (rank[ultimate_parent_v] > rank[ultimate_parent_u]) {
            parent[ultimate_parent_u] = ultimate_parent_v;
        } else {
            parent[ultimate_parent_v] = ultimate_parent_u;
            rank[ultimate_parent_u]++; // Increase rank if both have same rank
        }
    }

    // Union by Size
    void UnionBySize(int u, int v) {
        int ultimate_parent_u = findpar(u);
        int ultimate_parent_v = findpar(v);

        if (ultimate_parent_u == ultimate_parent_v) {
            return; // They are already in the same set
        }

        if (size[ultimate_parent_u] > size[ultimate_parent_v]) {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v]; // Increase size of the resulting set
        } else {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
    }
};
