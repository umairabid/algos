#include <vector>
#include <set>

#ifndef TREE_H
#define TREE_H

struct Tree {
    std::vector<std::vector<int>> nodes;
    void addEdge(int, int);
    void traverse(int);
    void fill(std::string);
    std::vector<int> getHeights(int);
};

#endif
