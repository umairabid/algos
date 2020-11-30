#include <vector>
#include <unordered_map>

#ifndef TREE_H
#define TREE_H

struct Tree {
    std::unordered_map<int, std::vector<int>> nodes;

    Tree();
    Tree(const Tree &tree);

    void addEdge(int, int);
    void traverse();
    void fill(std::string);
    void removeNode(int);
    
    int size();
    std::vector<int> dfs(int);
    std::vector<int> bfs(int);
    std::vector<int> getHeights(int);
    std::pair<int, int> findFarthest(int);
    std::vector<int> getLeafNodes();
    
    std::vector<int> findCenters();
};

#endif
