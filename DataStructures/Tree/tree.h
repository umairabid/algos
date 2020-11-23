#include <vector>
#include <set>

#ifndef TREE_H
#define TREE_H

struct Tree {
    std::vector<std::vector<int>> nodes;
    void addEdge(int, int);
    void traverse();
    void fill(std::string);
    std::vector<int> getHeights(int);
    std::vector<int> dfs(int);
    std::vector <int> bfs(int);
    std::pair<int, int> findFarthest(int);
};

#endif
