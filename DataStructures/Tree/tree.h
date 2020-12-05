#include <vector>
#include <unordered_map>

using namespace std;

#ifndef TREE_H
#define TREE_H

struct Tree {
    unordered_map<int, vector<int>> nodes;

    Tree();
    Tree(const Tree &tree);

    void addEdge(int, int);
    void traverse();
    void fill(string);
    void removeNode(int);
    
    int size();
    unordered_map<int, int> getHeights(int);
    unordered_map<int, int> getSizes(int);
    unordered_map<int, int> getMaxTrees(int);
    vector<int> dfs(int);
    vector<int> bfs(int);
    pair<int, int> findFarthest(int);
    vector<int> getLeafNodes();
    
    vector<int> findCenters();
};

#endif
