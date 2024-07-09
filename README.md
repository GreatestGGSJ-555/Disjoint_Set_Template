# Disjoint_Set_Template
Disjoint Set Data Structure (Union-Find) A disjoint set, also known as Union-Find, is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets. It provides efficient operations for:  Finding the representative (or parent) of a set containing a particular element. Union of two sets.


Key Concepts
1. Find with Path Compression
The findpar function finds the representative of the set containing node.
Path compression ensures that each node on the path from node to the root has its parent updated to the root. This flattens the structure, speeding up future operations.
2. Union by Rank
The UnionByRank function merges two sets based on the rank.
Rank is an upper bound on the height of the tree. The tree with a smaller rank is attached under the tree with a larger rank to keep the tree shallow.
3. Union by Size
The UnionBySize function merges two sets based on the size.
Size is the number of elements in the tree. The smaller tree is attached under the larger tree to maintain balance.
